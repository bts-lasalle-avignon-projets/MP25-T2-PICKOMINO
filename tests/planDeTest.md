Plan de test de la fonction verifierPresenceVers :

| Numéro du test | Description                      |         Entrée         | Résultat attendu |
|     :---:      |         -----------------        |         :---:          |      :---:       |
| *Test 2.1*     | 8 Dés - Ver présent              | *8, {2,5,4,6,3,2,4,1}* |      `true`      |
| *Test 2.2*     | 8 Dés - Ver présent              | *4, {5,4,3,6}*         |      `true`      |
| *Test 2.3*     | 4 Dés - Ver présent              | *1, {6}*               |      `true`      |
| *Test 2.4*     | 8 Dés - Pas de vers              | *8, {3,1,1,2,4,1,2,5}* |      `false`     |
| *Test 2.5*     | 4 Dés - Pas de vers              | *4, {4,5,2,3}*         |      `false`     |
| *Test 2.6*     | Tableau vide                     | *0, {}*                |      `false`     |

Plan de test de la fonction calculerScoreFinalTour :

| Numéro du test | Description                      |         Entrée         | Résultat attendu |
|     :---:      |         -----------------        |         :---:          |      :---:       |
| *Test 2.1*     | 8 Dés - 2 Vers                   | *8, {6,5,4,6,3,2,4,1}* |      `29`        |
| *Test 2.2*     | 4 Dés - 1 Ver                    | *4, {5,4,3,6}*         |      `17`        |
| *Test 2.3*     | 1 Dé - 1 Ver                     | *1, {6}*               |      `5`         |
| *Test 2.4*     | 8 Dés sans vers                  | *8, {3,1,1,2,4,1,2,5}* |      `0`         |
| *Test 2.5*     | 4 Dés sans vers                  | *4, {4,5,2,3}*         |      `0`         |
| *Test 2.6*     | Tableau vide                     | *0, {}*                |      `0`         |