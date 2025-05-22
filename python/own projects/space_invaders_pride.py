import pygame
import random
import sys
import json
import os
from pygame.locals import *

pygame.init()

BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
GREEN = (48, 194, 48)
RED = (255, 85, 85)
BLUE = (85, 170, 255)
ORANGE = (255, 170, 85)

PRIDE_COLORS = [
    (228, 3, 3),
    (255, 140, 0),
    (255, 237, 0),
    (0, 128, 38),
    (0, 77, 255),
    (117, 7, 135)
]

SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
FPS = 60
PLAYER_WIDTH = 50
PLAYER_HEIGHT = 30
PLAYER_SPEED = 5
PLAYER_MAX_LIVES = 3
INVULNERABLE_TIME = 30
BULLET_WIDTH = 3
BULLET_HEIGHT = 15
BULLET_SPEED = 7
ENEMY_WIDTH = 40
ENEMY_HEIGHT = 30
ENEMY_ROWS = 5
ENEMY_COLS = 10
ENEMY_HORIZONTAL_SPACING = 60
ENEMY_VERTICAL_SPACING = 50
ENEMY_SPEED = 1
ENEMY_DROP = 20
ENEMY_SHOOT_CHANCE = 0.005
BOSS_WIDTH = 120
BOSS_HEIGHT = 60
BOSS_HEALTH = 10
BOSS_SPEED = 2
BOSS_SHOOT_CHANCE = 0.03
SAFE_ZONE_WIDTH = 100
SAFE_ZONE_HEIGHT = 20
SAFE_ZONE_COUNT = 3

screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Space Invaders - Pride Edition")
clock = pygame.time.Clock()
HIGH_SCORES_FILE = "highscores.json"

class Player:
    def __init__(self):
        self.width = PLAYER_WIDTH
        self.height = PLAYER_HEIGHT
        self.x = SCREEN_WIDTH / 2 - self.width / 2
        self.y = SCREEN_HEIGHT - self.height - 20
        self.speed = PLAYER_SPEED
        self.color = WHITE
        self.rect = pygame.Rect(self.x, self.y, self.width, self.height)
        self.lives = 1
        self.invulnerable = False
        self.invulnerable_time = 0
        self.blink_state = True

    def update(self, keys):
        if keys[K_LEFT] and self.rect.left > 0:
            self.rect.x -= self.speed
        if keys[K_RIGHT] and self.rect.right < SCREEN_WIDTH:
            self.rect.x += self.speed
        self.x = self.rect.x
        self.y = self.rect.y
        if self.invulnerable:
            self.invulnerable_time -= 1
            if self.invulnerable_time % 5 == 0:
                self.blink_state = not self.blink_state
            if self.invulnerable_time <= 0:
                self.invulnerable = False
                self.blink_state = True

    def draw(self, surface):
        if self.invulnerable and not self.blink_state:
            return
        pygame.draw.rect(surface, WHITE, self.rect)
        points = [
            (self.x + self.width / 2, self.y - 10),
            (self.x + self.width, self.y),
            (self.x, self.y),
        ]
        pygame.draw.polygon(surface, WHITE, points)

    def hit(self):
        if not self.invulnerable:
            self.lives -= 1
            if self.lives > 0:
                self.invulnerable = True
                self.invulnerable_time = INVULNERABLE_TIME
                return False
            return True
        return False

class Bullet:
    def __init__(self, x, y, speed, color):
        self.width = BULLET_WIDTH
        self.height = BULLET_HEIGHT
        self.x = x
        self.y = y
        self.speed = speed
        self.color = color
        self.rect = pygame.Rect(self.x, self.y, self.width, self.height)

    def update(self):
        self.y -= self.speed
        self.rect.y = self.y

    def draw(self, surface):
        pygame.draw.rect(surface, self.color, self.rect)

class EnemyBullet(Bullet):
    def update(self):
        self.y += self.speed
        self.rect.y = self.y

class SafeZone:
    def __init__(self, x, y):
        self.width = SAFE_ZONE_WIDTH
        self.height = SAFE_ZONE_HEIGHT
        self.x = x
        self.y = y
        self.color = (0, 100, 255, 128)
        self.triangle_blocks = []
        self.active = True
        self.cooldown = 0
        self.max_cooldown = 300
        # Blöcke jetzt 14x14 Pixel (2x2 mal größer als vorher)
        block_size = 28  # 4x4 mal größer als das ursprüngliche 7x7
        rows = (self.height * 3) // block_size
        for row in range(rows):
            blocks_in_row = rows - row
            x_offset = (self.width - blocks_in_row * block_size) // 2
            for col in range(blocks_in_row):
                bx = self.x + x_offset + col * block_size
                by = self.y + row * block_size
                self.triangle_blocks.append(pygame.Rect(bx, by, block_size, block_size))

    def update(self):
        if not self.active:
            self.cooldown -= 1
            if self.cooldown <= 0:
                self.active = True
                self.color = (0, 100, 255, 128)

    def deactivate(self):
        self.active = False
        self.cooldown = self.max_cooldown
        self.color = (50, 50, 50, 128)

    def draw(self, surface):
        if not self.active:
            return
        for block in self.triangle_blocks:
            block_surface = pygame.Surface((block.width, block.height), pygame.SRCALPHA)
            block_surface.fill(self.color)
            surface.blit(block_surface, (block.x, block.y))

class Boss:
    def __init__(self, level):
        self.width = BOSS_WIDTH
        self.height = BOSS_HEIGHT
        self.x = SCREEN_WIDTH / 2 - self.width / 2
        self.y = 50
        self.speed = BOSS_SPEED
        self.direction = 1
        self.health = BOSS_HEALTH + (level // 2)
        self.max_health = self.health
        self.rect = pygame.Rect(self.x, self.y, self.width, self.height)
        self.color = (255, 0, 100)
        self.shoot_pattern = 0
        self.shoot_timer = 0

    def update(self):
        self.x += self.speed * self.direction
        if self.x <= 0 or self.x + self.width >= SCREEN_WIDTH:
            self.direction *= -1
        self.rect.x = self.x
        self.rect.y = self.y
        self.shoot_timer += 1

    def draw(self, surface):
        pygame.draw.rect(surface, self.color, self.rect)
        pygame.draw.rect(surface, (255, 255, 0), (self.x + 20, self.y + 15, 20, 10))
        pygame.draw.rect(surface, (255, 255, 0), (self.x + self.width - 40, self.y + 15, 20, 10))
        pygame.draw.rect(surface, (150, 150, 150), (self.x + 30, self.y - 15, 5, 15))
        pygame.draw.rect(surface, (150, 150, 150), (self.x + self.width - 35, self.y - 15, 5, 15))
        health_width = (self.width - 20) * (self.health / self.max_health)
        pygame.draw.rect(surface, (100, 100, 100), (self.x + 10, self.y - 30, self.width - 20, 10))
        pygame.draw.rect(surface, (255, 0, 0), (self.x + 10, self.y - 30, health_width, 10))

class Enemy:
    def __init__(self, x, y, row):
        self.width = ENEMY_WIDTH
        self.height = ENEMY_HEIGHT
        self.x = x
        self.y = y
        self.row = row
        self.rect = pygame.Rect(self.x, self.y, self.width, self.height)
        if row == 0:
            self.color = RED
        elif row < 3:
            self.color = BLUE
        else:
            self.color = ORANGE

    def update(self, direction):
        self.x += ENEMY_SPEED * direction
        self.rect.x = self.x

    def move_down(self):
        self.y += ENEMY_DROP
        self.rect.y = self.y

    def draw(self, surface):
        pygame.draw.rect(surface, self.color, self.rect)
        pygame.draw.rect(surface, BLACK, (self.x + 8, self.y + 8, 10, 5))
        pygame.draw.rect(surface, BLACK, (self.x + self.width - 18, self.y + 8, 10, 5))

class Game:
    def __init__(self):
        self.player = Player()
        self.player_bullets = []
        self.enemies = []
        self.enemy_bullets = []
        self.safe_zones = []
        self.score = 0
        self.enemy_direction = 1
        self.game_over = False
        self.font = pygame.font.Font(None, 36)
        self.small_font = pygame.font.Font(None, 24)
        self.level = 1
        self.score_multiplier = 1.0
        self.boss = None
        self.boss_mode = False
        self.player_name = ""
        self.high_scores = self.load_high_scores()
        self.name_entered = False
        self.input_active = False
        self.create_safe_zones()
        self.create_enemies()

    def load_high_scores(self):
        try:
            if os.path.exists(HIGH_SCORES_FILE):
                with open(HIGH_SCORES_FILE, "r") as f:
                    return json.load(f)
            return []
        except:
            return []

    def save_high_scores(self):
        self.high_scores.append({"name": self.player_name, "score": self.score})
        self.high_scores.sort(key=lambda x: x["score"], reverse=True)
        self.high_scores = self.high_scores[:3]
        with open(HIGH_SCORES_FILE, "w") as f:
            json.dump(self.high_scores, f)

    def create_safe_zones(self):
        self.safe_zones = []
        spacing = SCREEN_WIDTH // (SAFE_ZONE_COUNT + 1)
        for i in range(SAFE_ZONE_COUNT):
            x = spacing * (i + 1) - SAFE_ZONE_WIDTH // 2
            y = SCREEN_HEIGHT - 100
            self.safe_zones.append(SafeZone(x, y))

    def create_enemies(self):
        self.enemies = []
        rows_to_create = ENEMY_ROWS
        for row in range(rows_to_create):
            for col in range(ENEMY_COLS):
                x = col * ENEMY_HORIZONTAL_SPACING + 50
                y = row * ENEMY_VERTICAL_SPACING + 50
                self.enemies.append(Enemy(x, y, row))
        self.boss = None
        self.boss_mode = False

    def shoot_player_bullet(self):
        bullet_color = random.choice(PRIDE_COLORS)
        x = self.player.rect.centerx - BULLET_WIDTH / 2
        y = self.player.rect.top
        self.player_bullets.append(Bullet(x, y, BULLET_SPEED, bullet_color))

    def shoot_enemy_bullet(self, enemy):
        x = enemy.rect.centerx - BULLET_WIDTH / 2
        y = enemy.rect.bottom
        self.enemy_bullets.append(EnemyBullet(x, y, BULLET_SPEED, RED))

    def shoot_boss_bullet(self):
        if not self.boss:
            return
        if self.boss.shoot_timer >= 60:
            self.boss.shoot_timer = 0
            self.boss.shoot_pattern = (self.boss.shoot_pattern + 1) % 3
            if self.boss.shoot_pattern == 0:
                x = self.boss.rect.centerx - BULLET_WIDTH / 2
                y = self.boss.rect.bottom
                self.enemy_bullets.append(EnemyBullet(x, y, BULLET_SPEED, (255, 0, 0)))
            elif self.boss.shoot_pattern == 1:
                for offset in [-20, 0, 20]:
                    x = self.boss.rect.centerx - BULLET_WIDTH / 2 + offset
                    y = self.boss.rect.bottom
                    self.enemy_bullets.append(EnemyBullet(x, y, BULLET_SPEED, (255, 0, 0)))
            else:
                x = self.boss.rect.centerx - BULLET_WIDTH / 2
                y = self.boss.rect.bottom
                self.enemy_bullets.append(EnemyBullet(x, y, BULLET_SPEED * 1.5, (255, 0, 0)))

    def next_level(self):
        self.level += 1
        self.score_multiplier += 1.0
        self.enemy_bullets = []
        self.player_bullets = []
        self.boss = None
        self.create_enemies()
        if self.player.lives < PLAYER_MAX_LIVES:
            self.player.lives += 1
        pygame.time.delay(500)

    def update(self):
        if self.game_over:
            return
        for safe_zone in self.safe_zones:
            safe_zone.update()
        keys = pygame.key.get_pressed()
        self.player.update(keys)
        for bullet in self.player_bullets[:]:
            bullet.update()
            if bullet.y + bullet.height < 0:
                self.player_bullets.remove(bullet)
        for bullet in self.enemy_bullets[:]:
            bullet.update()
            if bullet.y > SCREEN_HEIGHT:
                self.enemy_bullets.remove(bullet)
        if self.boss_mode and self.boss:
            self.boss.update()
            if random.random() < BOSS_SHOOT_CHANCE:
                self.shoot_boss_bullet()
        hit_edge = False
        for enemy in self.enemies:
            enemy.update(self.enemy_direction)
            if enemy.rect.left <= 0 or enemy.rect.right >= SCREEN_WIDTH:
                hit_edge = True
            if random.random() < ENEMY_SHOOT_CHANCE:
                self.shoot_enemy_bullet(enemy)
        if hit_edge:
            self.enemy_direction *= -1
            for enemy in self.enemies:
                enemy.move_down()
        self.check_collisions()
        for enemy in self.enemies:
            if enemy.rect.bottom >= self.player.rect.top:
                self.end_game()
                break

    def check_collisions(self):
        if self.boss_mode and self.boss:
            for bullet in self.player_bullets[:]:
                if bullet.rect.colliderect(self.boss.rect):
                    if bullet in self.player_bullets:
                        self.player_bullets.remove(bullet)
                    self.boss.health -= 1
                    self.score += int(20 * self.score_multiplier)
                    if self.boss.health <= 0:
                        self.boss = None
                        self.boss_mode = False
                        self.score += int(500 * self.score_multiplier)
                        if not self.enemies:
                            self.next_level()
        for bullet in self.player_bullets[:]:
            for enemy in self.enemies[:]:
                if bullet.rect.colliderect(enemy.rect):
                    if bullet in self.player_bullets:
                        self.player_bullets.remove(bullet)
                    if enemy in self.enemies:
                        self.enemies.remove(enemy)
                    self.score += int((ENEMY_ROWS - enemy.row) * 10 * self.score_multiplier)
                    if not self.enemies and not self.boss_mode:
                        self.next_level()
                    break
        for bullet in self.enemy_bullets[:]:
            safe_zone_hit = False
            for safe_zone in self.safe_zones:
                if safe_zone.active:
                    for block in safe_zone.triangle_blocks[:]:
                        if bullet.rect.colliderect(block):
                            if bullet in self.enemy_bullets:
                                self.enemy_bullets.remove(bullet)
                            safe_zone.triangle_blocks.remove(block)
                            safe_zone_hit = True
                            break
                    if safe_zone_hit:
                        break
            if not safe_zone_hit and bullet.rect.colliderect(self.player.rect):
                if bullet in self.enemy_bullets:
                    self.enemy_bullets.remove(bullet)
                if self.player.hit():
                    self.end_game()
                break

    def handle_name_input(self, event):
        if not self.input_active:
            return
        if event.type == KEYDOWN:
            if event.key == K_RETURN:
                self.input_active = False
                self.name_entered = True
                self.save_high_scores()
            elif event.key == K_BACKSPACE:
                self.player_name = self.player_name[:-1]
            else:
                if len(self.player_name) < 10:
                    self.player_name += event.unicode

    def draw(self):
        screen.fill(BLACK)
        self.draw_stars()
        for safe_zone in self.safe_zones:
            safe_zone.draw(screen)
        self.player.draw(screen)
        for bullet in self.player_bullets:
            bullet.draw(screen)
        for enemy in self.enemies:
            enemy.draw(screen)
        for bullet in self.enemy_bullets:
            bullet.draw(screen)
        score_text = self.font.render(f"Score: {self.score}", True, WHITE)
        level_text = self.font.render(f"Level: {self.level}", True, WHITE)
        multiplier_text = self.small_font.render(f"Multiplikator: x{self.score_multiplier:.1f}", True, GREEN)
        lives_text = self.font.render(f"Leben: {self.player.lives}", True, RED)
        screen.blit(score_text, (10, 10))
        screen.blit(level_text, (10, 40))
        screen.blit(multiplier_text, (10, 70))
        screen.blit(lives_text, (SCREEN_WIDTH - 120, 10))
        if self.game_over:
            self.draw_game_over()

    def draw_stars(self):
        for _ in range(100):
            x = random.randint(0, SCREEN_WIDTH - 1)
            y = random.randint(0, SCREEN_HEIGHT - 1)
            size = random.randint(1, 2)
            pygame.draw.rect(screen, WHITE, (x, y, size, size))

    def draw_game_over(self):
        overlay = pygame.Surface((SCREEN_WIDTH, SCREEN_HEIGHT), pygame.SRCALPHA)
        overlay.fill((0, 0, 0, 200))
        screen.blit(overlay, (0, 0))
        game_over_text = self.font.render("Game Over", True, WHITE)
        score_text = self.font.render(f"Your Score: {self.score}", True, WHITE)
        screen.blit(game_over_text, (SCREEN_WIDTH // 2 - game_over_text.get_width() // 2, SCREEN_HEIGHT // 2 - 120))
        screen.blit(score_text, (SCREEN_WIDTH // 2 - score_text.get_width() // 2, SCREEN_HEIGHT // 2 - 70))
        if not self.name_entered:
            name_prompt = self.font.render("Enter your name:", True, WHITE)
            name_text = self.font.render(self.player_name + ("_" if self.input_active else ""), True, GREEN)
            screen.blit(name_prompt, (SCREEN_WIDTH // 2 - name_prompt.get_width() // 2, SCREEN_HEIGHT // 2 - 20))
            screen.blit(name_text, (SCREEN_WIDTH // 2 - name_text.get_width() // 2, SCREEN_HEIGHT // 2 + 20))
            hint_text = self.small_font.render("Press ENTER when finished", True, WHITE)
            screen.blit(hint_text, (SCREEN_WIDTH // 2 - hint_text.get_width() // 2, SCREEN_HEIGHT // 2 + 60))
        else:
            highscore_title = self.font.render("Highscores:", True, WHITE)
            screen.blit(highscore_title, (SCREEN_WIDTH // 2 - highscore_title.get_width() // 2, SCREEN_HEIGHT // 2 - 20))
            for i, score in enumerate(self.high_scores):
                score_entry = self.font.render(f"{i+1}. {score['name']}: {score['score']}", True, GREEN)
                screen.blit(score_entry, (SCREEN_WIDTH // 2 - score_entry.get_width() // 2, SCREEN_HEIGHT // 2 + 20 + i * 40))
            restart_text = self.font.render("Press SPACE to play again", True, GREEN)
            screen.blit(restart_text, (SCREEN_WIDTH // 2 - restart_text.get_width() // 2, SCREEN_HEIGHT // 2 + 140))

    def end_game(self):
        self.game_over = True
        self.input_active = True

    def restart(self):
        self.player = Player()
        self.player_bullets = []
        self.enemy_bullets = []
        self.safe_zones = []
        self.score = 0
        self.enemy_direction = 1
        self.game_over = False
        self.level = 1
        self.score_multiplier = 1.0
        self.boss = None
        self.boss_mode = False
        self.player_name = ""
        self.name_entered = False
        self.input_active = False
        self.create_safe_zones()
        self.create_enemies()

def main():
    game = Game()
    running = True
    while running:
        for event in pygame.event.get():
            if event.type == QUIT:
                running = False
            elif event.type == KEYDOWN:
                if event.key == K_SPACE:
                    if not game.game_over:
                        game.shoot_player_bullet()
                    elif game.name_entered:
                        game.restart()
                elif event.key == K_ESCAPE:
                    running = False
            if game.game_over and not game.name_entered:
                game.handle_name_input(event)
        game.update()
        game.draw()
        pygame.display.flip()
        clock.tick(FPS)
    pygame.quit()
    sys.exit()

if __name__ == "__main__":
    main()
