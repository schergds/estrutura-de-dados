1) o que é e pra que serve recursão?
recursão é quando um método chama ele mesmo dentro dele, criando um empilhamento.
serve para substituir os laços de repetição convencionais.

---

2) o programador, ao fazer um método recursivo, precisa garantir 3 situações. Quais?
garantir que a variável de controle seja inicializada
garantir que tenha o teste de parada
garantir que tenha a transformação da variável de controle

---

3) Em que momento no código exemplo o empilhamento acontece? Como é possível visualizar isso no código?
o empilhamento acontece no momento em que o método é chamado dentro dele mesmo "mostraPares (v, n - 1)".
esse empilhamento continuará até que o teste de parada "if (n > 0)" retorne falso.

---

4) Imagine o método recursivo contaPares(). Ele deve contar os números pares de um vetor de inteiros de tamanho n.
- quais seriam os parâmetros do método?
o ponteiro v que aponta para um vetor inserido na chamada da função, e um inteiro n que serve para o teste de parada e acesso ao índice do vetor.
- qual seria a variável de controle?
int n.
- no código do método, como seria a chamada do método para garantir a recursão?
o else não deveria estar comentado para garantir a recursão.

---

5) Imagine um método recursivo contaPares(). Contudo, vai contar os números pares de uma lista encadeada simples.
- qual é o parâmetro?
uma célula passada dentro da main.
- qual é o tipo de retorno do método?
ele retorna true e empilha novamente o método com o próximo elemento da Célula caso seja par, e se o else não estivesse comentado e o valor for ímpar ele retornaria false e empilharia novamente também.
- E qual seria a variável de controle e no código do método e como seria a chamada do método para garantir a recursão?
A variável de controle é enquanto existir um valor não-nulo na célula e a chamada do método para garantir deve ser com o próximo elemento da célula.
