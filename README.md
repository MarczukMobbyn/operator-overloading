Biblioteka Arytmetyki Dowolnej Precyzji (CNumber)
Opis projektu:
Projekt zawiera implementację klasy CNumber w języku C++, która umożliwia wykonywanie operacji matematycznych na liczbach o dowolnej wielkości, ograniczonych jedynie dostępną pamięcią operacyjną. Klasa została zaprojektowana z myślą o obsłudze różnych systemów liczbowych (podstaw) oraz zapewnieniu bezpieczeństwa zarządzania zasobami dynamicznymi.

Główne cechy:
  Obsługa systemów liczbowych: Klasa umożliwia definiowanie podstawy systemu (np. podstawa 2, 4, 10 itp.) i automatyczną konwersję między nimi podczas operacji.

  Przeciążanie operatorów: Zaimplementowano pełne wsparcie dla operatorów arytmetycznych (+, -, *, /) oraz operatorów przypisania dla typów int oraz CNumber.

  Zarządzanie pamięcią: Implementacja wykorzystuje dynamiczne tablice (int* pi_number) do przechowywania cyfr w celu optymalizacji obliczeń.

  Obsługa błędów: Projekt zawiera dedykowany mechanizm wyjątków dla operacji niedozwolonych, takich jak dzielenie przez zero.

Szczegóły techniczne:
  Pamięć i cykle życia: Zgodnie z zasadą "Rule of Three", zaimplementowano destruktor, konstruktor kopiujący oraz operator przypisania, co gwarantuje poprawne wykonywanie głębokich kopii (deep copy) i zapobiega wyciekom pamięci.

Algorytmy:

  Reprezentacja: Cyfry przechowywane są w kolejności od najmniej znaczącej, co upraszcza implementację algorytmów dodawania i mnożenia.

  Konwersja: Do zmiany podstawy systemu liczbowego wykorzystano algorytm Hornera.

  Dzielenie: Implementacja algorytmu dzielenia pisemnego z obsługą reszty.

  Zgodność typów: Metody przyjmują referencje do obiektów, co ogranicza niepotrzebne kopiowanie danych podczas wykonywania operacji złożonych.

Struktura plików:
  CNumber.h / CNumber.cpp: Główna logika klasy, definicje operatorów i algorytmów arytmetycznych.

  DividedByZeroException.h: Definicja klasy wyjątku dziedziczącej po std::exception.

  main.cpp: Przykłady użycia, prezentujące inicjalizację obiektów, operacje arytmetyczne oraz przechwytywanie wyjątków.
