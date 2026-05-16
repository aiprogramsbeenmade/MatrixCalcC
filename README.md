# MatrixCalcC
MatrixCalcC è un programma open source sulla risoluzione di problemi lineari.
Attualmente è ancora in via di sviluppo.

## 🚀 Funzioni
Attualmente è possibile risolvere matrici e sistemi lineari. Di seguito le funzioni per matrici e sistemi lineari.
### Matrici
1. Determinante;
2. Rango;
3. Triangolarizzazione;
4. Traccia;
5. Prodotto Riga per Colonna;
6. Trasposta;

### Sistemi Lineari
1. Risoluzione con Operazioni Elementari;
2. Risoluzione con Cramer;
3. Calcolare la matrice completa;

# 💻 Requisiti e Installazione

### Requisiti
- Compilatore GCC (o qualsiasi compilatore C standard).
- Libreria `math.h`.
- (facoltativo) `make` installato.

### Installazione

1. **Clona la repository:**
```bash
git clone https://github.com/aiprogramsbeenmade/MatrixCalcC.git
```
2. **Compila il progetto:**
```bash
gcc main.c src/algebra.c src/menumatrix.c src/menusystem.c -o MatrixCalcC
```
oppure:

```bash
make
```

3. **Avvia il programma:**
```bash
./MatrixCalcC
```

# ⚖️ Licenza
Il progetto è sotto licenza MIT, consultare il file `LICENSE` per ulteriori dettagli.