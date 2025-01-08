Plan de test de la fonction calculerScoreFinalTour :

| Numéro du test | Description                      |         Entrée         | Résultat attendu |
|     :---:      |         -----------------        |         :---:          |      :---:       |
| *Test 1.1*     | 8 Dés retenus valide avec un ver | *8, {2,5,4,V,3,2,4,1}* |      `26`        |
| *Test 1.2*     | 4 Dés retenus valide avec un ver | *4, {5,4,3,V}*         |      `17`        |
| *Test 1.3*     | 1 Dés retenu valide avec un ver  | *1, {V}*               |      `5`         |
| *Test 1.4*     | 8 Dés retenus invalide sans ver  | *8, {3,1,1,2,4,1,2,5}* |      `0`         |
| *Test 1.5*     | 4 Dés retenus invalide sans ver  | *4, {4,5,2,3}*         |      `0`         |
| *Test 1.6*     | Tableau dés retenus vide         | *{}*                   |      `0`         |