Line follower

Bill Of Materials:
https://docs.google.com/spreadsheets/d/1_GYeWjBXVv_4aekasxN6_g4DxXadq2Kq5P1_7F1olAA/edit#gid=1680300681

Explicatii:

Robotul are in fata un vector de 8 senzori de lumina infrarosie. Fiecare senzor are o sursa care emite lumina IR si un receptor de lumina IR. Practic fiecare senzor in parte emite lumina IR si apoi observa cat primeste inapoi. Fiecare senzor returneaza un semnal digital cu valoarea 0 cand se afla pe fundalul alb iar cand intalneste linia neagra care trebuie urmarita returneaza 1.

Dintre cei 8 senzori ai placutei folosesc doar senzorii D2-D6 deoarece incerc sa mentin robotul centrat pe linie, plus ca senzorul D7 pare a fi defectuos.

In functia void loop(); citesc intr-un for output-ul fiecarui senzor iar in functie de care senzor returneaza 1 apelez o functie care transmite curent electric motoarelor de diferita intensitate.
