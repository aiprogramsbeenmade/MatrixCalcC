# MatrixCalc - Algebra Lineare in C

Un programma versatile scritto in C per eseguire operazioni avanzate su matrici quadrate e rettangolari. Progettato con un'attenzione particolare alla precisione numerica e alla stabilità degli algoritmi.

## 🚀 Funzionalità

Il programma offre un menù interattivo per eseguire le seguenti operazioni:

1.  **Prodotto Riga per Colonna**: Calcolo del prodotto tra due matrici compatibili.
2.  **Trasposta**: Generazione della matrice trasposta.
3.  **Traccia**: Calcolo della somma degli elementi sulla diagonale principale.
4.  **Determinante**: Implementazione per matrici 2x2, 3x3 e superiori.
5.  **Triangolarizzazione di Gauss**: Trasformazione della matrice in forma a gradini superiore (Upper Triangular).
6.  **Calcolo del Rango**: Determina il numero di righe linearmente indipendenti sfruttando la riduzione di Gauss.

## 🛠️ Dettagli Tecnici

### Gestione del Rango e della Triangolarizzazione
Per garantire che il programma funzioni con qualsiasi matrice, è stato implementato l'algoritmo di **Eliminazione di Gauss con Pivoting Parziale**.
- **Stabilità:** Il programma cerca il pivot massimo in ogni colonna per ridurre l'errore di arrotondamento.
- **Precisione:** Le operazioni interne utilizzano il tipo `float` con una tolleranza di `1e-9` per gestire correttamente i valori vicini allo zero prodotti dai calcoli floating-point.

### Requisiti
- Compilatore GCC (o qualsiasi compilatore C standard).
- Libreria `math.h` (utilizzare il flag `-lm` in fase di compilazione).

## 💻 Installazione e Utilizzo

1. **Clona la repository**:
   ```bash
   git clone https://github.com/aiprogramsbeenmade/MatrixCalcC.git
   
2. **Compila il progetto**:
    ```bash
   gcc main.c algebra.c -o main -lm
   
3. **Esegui il programma**:
    ```bash
   ./main

## ⚖️ Progetto sotto licenza MIT
Per ulteriori informazioni visitare il file `LICENSE`.