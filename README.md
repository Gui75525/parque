Estão ai os testes que avaliam o programa
podem usar este script para ele testar os testes todos de uma so vez
for i in T*; do ./parque <  $i/input.txt > out ; diff $i/output.txt out; done ;
