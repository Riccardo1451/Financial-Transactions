# Notebook Finanziario

Notebook Finanziario è un'applicazione che consente agli utenti di tenere traccia 
delle proprie transazioni finanziarie quotidiane, permettendo di monitorare entrate 
e uscite con la possibilità di confrontare le registrazioni con l'estratto conto bancario.

## Funzionalità Principali
- **Registrazione Transazioni**: Aggiungi e gestisci entrate e uscite.
- **Modifica e Cancellazione**: Modifica o rimuovi transazioni esistenti.
- **Visualizzazione Transazioni**: Consulta un elenco delle transazioni registrate.
- **Confronto Estratto Conto**: Verifica quali transazioni sono conciliate e quali no.

## Tecnologie Utilizzate
- **Linguaggio**: C++
- **Librerie**: Google Test per la fase di Unit Testing

## Come Installare
Per installare e compilare l'applicazione:
```bash
git clone <https://github.com/Riccardo1451/Financial-Transactions.git>
mkdir build
cd build
cmake ..
make
```

## Test
Per eseguire gli Unit Test, utilizza il comando:

```bash
cmake --build . --target run_tests
