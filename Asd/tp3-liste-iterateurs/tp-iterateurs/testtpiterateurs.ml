open Listeit

let imprimer_avec_iterateur l =
  let it = iterateur_en_debut l in
  while not(est_en_fin it) do
    Printf.printf "%d " (valeur it);
    avancer it;
  done;
  Printf.printf "%d\n" (valeur it)
	  
let imprimer_avec_iterateur_envers l =
  let it = iterateur_en_fin l in
  while not(est_en_debut it) do
    Printf.printf "%d " (valeur it);
    reculer it;
  done;
  Printf.printf "%d\n" (valeur it)
 

(*
let inserer_trie l e =
  l*)

let _ =
  let l1 = liste_vide ()
  in
  ajouter_en_tete l1 1;
  ajouter_en_tete l1 2;
  ajouter_en_tete l1 3;
  ajouter_en_tete l1 4;
  imprimer_sans_iterateur l1 (Printf.printf "%d ");
  imprimer_sans_iterateur_envers l1 (Printf.printf "%d ");

  (* test 1 : les itérateurs *)
  Printf.printf "=== Test 1 - impression avec iterateurs ===\n";
  imprimer_avec_iterateur l1;
  imprimer_avec_iterateur_envers l1;
  
  (* test 2 : insertion avant *)
  Printf.printf "=== Test 2 - insertion avant de 10 ===\n";
  let it = iterateur_en_fin l1
  in
  reculer it;
  inserer_avant it 10;
  Printf.printf "%d\n" (valeur it);
  imprimer_avec_iterateur l1;
  imprimer_avec_iterateur_envers l1;
  
  (* test 3 : insertion après *)
  Printf.printf "=== Test 3 - insertion après de 100 ===\n";
  let it = iterateur_en_debut l1
  in
  avancer it;
  inserer_apres it 100;
  Printf.printf "%d\n" (valeur it);
  imprimer_avec_iterateur l1;
  imprimer_avec_iterateur_envers l1;

  (* test 4 :  insertion avant le premier element *)
  Printf.printf "=== Test 4 - insertion avant le début de 20 ===\n";
  let it = iterateur_en_debut l1
  in
  inserer_avant it 20;
  Printf.printf "%d\n" (valeur it);
  imprimer_avec_iterateur l1;
  imprimer_avec_iterateur_envers l1;
  
  (* test 5 :  insertion après le dernier element *)
  Printf.printf "=== Test 5 - insertion après la fin de 200 ===\n";
  let it = iterateur_en_fin l1
  in
  inserer_apres it 200;
  Printf.printf "%d\n" (valeur it);
  imprimer_avec_iterateur l1;
  imprimer_avec_iterateur_envers l1;

  (* test 6 : insérer trier : à vous d'écrire ce test *)
  Printf.printf "=== Test 6 - insertion trie avec plusieurs valeurs ===\n";
  let l2 = liste_vide ()
    in
    ajouter_en_tete l2 1;
    ajouter_en_tete l2 2;
    ajouter_en_tete l2 3;
    ajouter_en_tete l2 5;
  let e = ref 0 in
  imprimer_avec_iterateur l2;
  imprimer_avec_iterateur_envers l2;
  Printf.printf "insertion de %d\n" !e ;
  inserer_trie l2 !e ;
  imprimer_avec_iterateur l2;
  imprimer_avec_iterateur_envers l2;
  e := 3 ;
  imprimer_avec_iterateur l2;
  imprimer_avec_iterateur_envers l2;
  Printf.printf "insertion de %d\n" !e ;
  inserer_trie l2 !e ;
  imprimer_avec_iterateur l2;
  imprimer_avec_iterateur_envers l2;
  e := 4 ;
  imprimer_avec_iterateur l2;
  imprimer_avec_iterateur_envers l2;
  Printf.printf "insertion de %d\n" !e ;
  inserer_trie l2 !e ;
  imprimer_avec_iterateur l2;
  imprimer_avec_iterateur_envers l2;
  e := 6 ;
  imprimer_avec_iterateur l2;
  imprimer_avec_iterateur_envers l2;
  Printf.printf "insertion de %d\n" !e ;
  inserer_trie l2 !e ;
  imprimer_avec_iterateur l2;
  imprimer_avec_iterateur_envers l2;
  
 (*
  (* test 7 :  suppression devant *)
  Printf.printf "=== Test 7 - suppression du 2e element puis de la tete ===\n";
  let it = iterateur_en_debut l1
  in
  avancer it;
  Printf.printf "suppression de %d\n" (valeur it);
  supprimer it;
  imprimer_avec_iterateur l1;
  imprimer_avec_iterateur_envers l1;
  reculer it;
  Printf.printf "suppression de %d\n" (valeur it);
  supprimer it;
  Printf.printf "valeur de it apres suppression : %d\n" (valeur it);
  imprimer_avec_iterateur l1;
  imprimer_avec_iterateur_envers l1;

  (* test 8 :  suppression derriere *)
  Printf.printf "=== Test 8 - suppression de l'avant dernier element puis de la queue ===\n";
  let it = iterateur_en_fin l1
  in
  reculer it;
  Printf.printf "suppression de %d\n" (valeur it);
  supprimer it;
  imprimer_avec_iterateur l1;
  imprimer_avec_iterateur_envers l1;
  Printf.printf "suppression de %d\n" (valeur it);
  supprimer it;
  try
    (* devrait lever l'exception IterateurInvalide *)
    Printf.printf "valeur de it apres suppression : %d\n" (valeur it);
  with
      IterateurIndefini -> begin
	Printf.printf "l'itérateur est indéfini !\n";
    end;
  imprimer_avec_iterateur l1;
  imprimer_avec_iterateur_envers l1;*)
  
