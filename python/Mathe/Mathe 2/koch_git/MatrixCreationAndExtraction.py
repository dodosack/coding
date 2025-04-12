```python
import numpy as np

# Zeilen mit der gleichen Länge erstellen
row1 = np.arange(-1.5, 4, 0.5)  # Schrittweite 0.5 (Länge 12)
row2 = np.arange(-1.3, 4, 0.5)  # Schrittweite 0.5 (Länge 12)
row3 = np.arange(-1.2, 4, 0.5)  # Schrittweite 0.5 (Länge 12)

# Matrix A zusammensetzen
A = np.array([row1, row2, row3])

# Matrix B extrahieren: 3. Zeile (Index 2), Spalten 2, 4, 6 -> Indizes 2, 4, 6
B = A[[2, 0], [2, 4, 6]].reshape(2, 3)

print("Matrix A:")
print(A)
print("\nMatrix B:")
print(B)
```




### Hinweise:
- Bei Bedarf können Sie die Schrittweite oder die Endpunkte der Zeilen anpassen, je nach gewünschtem Ergebnis.
- Falls Sie mit unterschiedlich langen Zeilen arbeiten möchten, kann ein objektartiger Datentyp (`dtype=object`) verwendet werden, aber das führt nicht zu einer rechteckigen Matrix.