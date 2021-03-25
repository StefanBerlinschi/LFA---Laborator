# LFA---Laborator
Tema de la laboratorul de limbaje formale si automate: un automat Moore.

Implementarea a fost facuta folosind un graf orientat, cu o matrice de adiacenta
de caractere, reprezentand drumurile ce pot fi parcurse prin litere. Intr-un alt vector
au fost retinute output-urile pentru fiecare stare, specific automatelor Moore.

Programul parcurge fiecare cuvant folosind o functie ce primeste starea 
curenta si litera si returneaza starea in care am ajuns, sau -1 daca nu exista 
nicio stare in care putem ajunge. Starile sunt retinute intr-un alt vector numit 
"traseu" ce va fi afisat in cazul in care starea in care am ajuns este una finala.
