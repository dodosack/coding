#include <ctime>
#include <iostream>
#include <string>


using namespace std;
enum class Object {
    ROCK = 1, // Damit es bei  1 begint
    SCISSORS,
    PAPER
};

// Aufzählungstyp für mögliche Spielausgänge

enum class Result { // da es ein ENUM CLASS ist choice nicht numerisch

    PLAYER_ONE_WINS,
    PLAYER_TWO_WINS,
    DRAW
};

// Struktur für einen Spieler bestehend aus Name und Wahl des Spielers
struct Player {
    string name;
    Object choice; // das kann schrere stein papier 0 1 2 sein....
};
string insert_name();

Object determine_choice(string choice);

void   print_result(Player player_1, Player player_2);
Result determine_result(Player player_1, Player player_2);
Object choose();
void   print_choice(Player player);
string get_name(Object object);





int main(int argc, char* argv[]) {
    Player player_1, player_2;
    player_1.name   = "Computer";
    player_2.name   = insert_name();
    player_1.choice = determine_choice(player_2.name);
    cout << "Der Computer hat seine Wahl getroffen." << endl;
    player_2.choice = choose();
    print_choice(player_1);
    print_choice(player_2);
    print_result(player_1, player_2);

    return 0;
}


// Aufzählungstyp für wählbare Objekte
// STEIN - 0, SCHERE - 1, PAPIER - 2


// Name des Spielers eingeben
string insert_name() {
    // HIER programmieren:
    std ::cout << "Name des Spielers :" << std::endl;

    std::string name; // zum zwischenspeichern

    cin.clear();
    std::getline(std::cin, name); // ganze zeile einlesen bis\n


    // Den Namen des Spielers von der Konsole einlesen und zurückgeben
    //
    //
    return name;

    // Tip: für das Einlesen eines Strings gibt es eine bestimmte Funktion, siehe auch Vorlesung Folie "Eine Zeile als String einlesen"
}

Object determine_choice(string choice) {
    if (choice.compare("CoderunnerTestValueROCK") == 0) { // vergleicht ob choice == "CoderunnerTestV"...
        return Object::ROCK;
    } else if (choice.compare("CoderunnerTestValueSCISSORS") == 0) {
        return Object::SCISSORS;
    } else if (choice.compare("CoderunnerTestValuePAPER") == 0) {
        return Object::PAPER;
    } else {
        // Den Computer zufällig waehlen lassen.

        // HIER beantworten Sie folgende Fragen:
        // Was bewirkt die funktion srand?
        // Warum wird hier die Zeit (time) als Eingabe für die Funktion srand verwendet?
        // Wie funktioniert die funktion rand?
        // Warum wird hier modulo 3 verwendet?

        srand(static_cast<int>(time(nullptr)));
        int choice = (rand() % 3) + 1; // weil enum class bei 1 beginnt

        return static_cast<Object>(choice); // umwandlung in string
    }
}





// Die Wahl des Spielers abfragen
Object choose() {

    // HIER programmieren:
    std ::cout << "Bitte Objektwahl eingeben (1 = Stein, 2 = Schere, 3 = Papier):" << std::endl;


    // Die Wahl des Spielers von der Konsole einlesen und zurückgeben
    int temp; // zum zwischenspeichern

    do {

        std::cin >> temp;

    } while (temp > 3 || temp < 1);


    Object temp_cast;
    temp_cast = static_cast<Object>(temp);
    return temp_cast;


    // Stellen sie sicher, dass es sich um eine gültige Wahl handelt!
    // TIP: Nutzen Sie dazu eine geeignete Schleife. Siehe auch Vorlesung Folie "Annehmende Schleifenanweisungen – Do"
}



// Einen Text mit dem Namen des Spielers und seiner Wahl ausgeben
void print_choice(Player player) {

    // HIER programmieren:
    // Auf der Konsole ausgeben, für welches Objekt sich der Spieler entschieden hat.
    std::string choice;

    choice = get_name(player.choice);

    std::cout << player.name << " hat das Objekt " << choice << " gewaehlt" << std::endl;

    // z.B.: "Computer hat das Objekt Schere gewählt"
    // TIP: Nutzen sie hierzu die Funktion get_name
}


// Die Wahl von Stein etc. als String zurückgeben lassen
string get_name(Object object) {

    // HIER programmieren:
    // Abhängig vom vorliegenden Objekt einen entsprechenden String zurückgeben.
    //
    // z.B: Wenn object dem Wert Object::ROCK entspricht, dann String "Stein" zurückgeben

    if (object == Object::ROCK) {

        return "Stein";
    } else if (object == Object::PAPER) {
        return "Papier";
    } else
        return "Schere";
}
// // string get_name(Object object) {
//     switch (object) {
//         case Object::ROCK: return "Stein";
//         case Object::SCISSORS: return "Schere";
//         case Object::PAPER: return "Papier";
//         default: return "Unbekannt";
//     }
// }



Result determine_result(Player player_1, Player player_2) {

    // HIER programmieren:
    // Vergleichen Sie die gewählten Objekte, ermitteln sie das Spielergebnis und geben sie es zurück.
    if (player_1.choice == player_2.choice) {
        return Result::DRAW;
    } else if ((player_1.choice == Object::ROCK && player_2.choice == Object::SCISSORS) ||
               (player_1.choice == Object::SCISSORS && player_2.choice == Object::PAPER) ||
               (player_1.choice == Object::PAPER && player_2.choice == Object::ROCK)) {

        return Result::PLAYER_ONE_WINS;
    }

    else {
        return Result::PLAYER_TWO_WINS;
    }

    // TIP: Wenn Sie für den Vergleich mit ganzene Zahlen _rechnen_ wollen, dann nutzen sie den static_cast, siehe auch Vorlesung Folie "Casts in C++: Static_cast"
}



void print_result(Player player_1, Player player_2) {

    // HIER programmieren:
    // Ermitteln Sie zunächst das Spielergebnis. Nutzen sie dazu die Funktion determine_result.

    Result winner = determine_result(player_1, player_2);


    // Geben Sie anschließend auf der Konsole aus, wer gewonnen hat.

    if (winner == Result::DRAW) {
        std::cout << "Unentschieden" << std::endl;
    } else if (winner == Result::PLAYER_ONE_WINS) {
        std::cout << player_1.name << " hat gewonnen!" << std::endl;
        // Könnte auch nur computer schreiben aber so sauberer und ausbaufähiger

    }

    else {

        std::cout << player_2.name << " hat gewonnen!" << std::endl;
    }

    // z.B: "Spieler Computer hat gewonnen" oder "Unentschieden"
}
