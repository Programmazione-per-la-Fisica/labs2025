# Commenti su soluzioni Lab3 a.a. 2025/2026

- Usare sempre un blocco `{}` per `if`/`while`/`for`
- Per le funzioni e per i blocchi `if`/`while`/`for`, non ci va il `;` dopo la `}`

```c++
if (...) {
  ...
}; // no ;

void f(...) {
  ...
}; // no ;
```

- La funzione non e' `pow`, ma `std::pow`, includendo `<cmath>`
- Piuttosto di `std::pow(x, 2)` si puo' usare `x * x`
- Nei test non vale la pena usare SUBCASE se nella parte comune c'e' solo la creazione di uno o piu' oggetti; tanto vale
  avere piu' `TEST_CASE` oppure semplicemente piu' scope dentro uno stesso `TEST_CASE`:

```c++
TEST_CASE(...) {
  {
    ...
  }
  {
    ...
  }
}
```

- Ricordarsi la formattazione del codice, includendo un file di configuarazione `.clang-format`
- I valori usati nei test devono essere calcolati a mano ovvero usando strumenti alternativi
  (foglio elettronico, calcolatrice, wolfram alpha, root, ...). NON vanno calcolati usando il proprio codice
- Nella definizione di una funzione, i controlli dei casi di errore (ad es. relativi ai parametri della funzione)
  e' preferibile farli prima dei calcoli veri e propri
- Nei nomi di file/directory evitare gli spazi e usare preferibilmente solo lettere minuscole
- Attenzione ai file messi nell'archivio per la consegna
- Evitare commenti eccessivi nel codice
- Preferire l'uso delle parentesi graffe `{}` per l'inizializzazione degli oggetti
- Nelle espressioni non mettere parentesi `()` evidentemente superflue, ad es. si sa che la moltiplicazione ha
  precedenza maggiore dell'addizione
- Se possibile, preferire l'uso di un inizializzatore per le variabili membro di una `struct`/`class`
  rispetto alla loro inizializzazione in un costruttore:

> [!TIP]
> Ad esempio è meglio:
>
> ```c++
> class C {
>   int a_{0};
>  public:
>   C(...) { ... }
> };
> ```
>
> rispetto a:
>
> ```c++
> class C {
>   int a_;
>  public:
>   C(...) : a_{0} { ... }
> };
> ```

- Per chi sa cosa sono, evitare variabili globali!
- Non sollevare (`throw`) eccezioni di tipo `std::exception`, ne' tantomento di tipo `int`, `char` o `std::string`.
  Limitarsi a eccezioni _derivate_ da `std::exception`, ad es. `std::runtime_error`
