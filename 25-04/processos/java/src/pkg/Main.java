package pkg;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;

public class Main{
    /***
     * Método estático ou de classe responsável por gerar processos aleatórios entre 1 a 1000
     * distribuindo em duas filas:
     * @param filaPrioritaria - fila prioritária (números abaixo de 500)
     * @param filaNormal - fila normal (números acima de 500)
     * @param quantidadeProcessos - quantidade de processos que deseja realizar
     */
    public static void gerarProcessosEmFilas(Queue<Processo> filaPrioritaria, Queue<Processo> filaNormal, int quantidadeProcessos){
        int numeroProcessoGerado;
        Random random = new Random();
        //Rotina para gerar 10000 processos entre 1 e 1000
        for (int i = 0; i < quantidadeProcessos; i++) {
            numeroProcessoGerado = random.nextInt(0, 1001);

            switch(numeroProcessoGerado){
                case 0:
                    System.out.println("Atendendo: " + filaPrioritaria.poll());
                    break;
                case 500:
                    System.out.println("Atendendo: " + filaNormal.poll());
                    break;
                default:
                    if(numeroProcessoGerado < 500){
                        Processo processoTmp = new Processo(numeroProcessoGerado, "Processo de alta prioridade");
                        if(!filaPrioritaria.contains(processoTmp)){
                            filaPrioritaria.offer(processoTmp);
                            System.out.println(processoTmp);
                        }
                    }
                    else{
                        Processo processoTmp = new Processo(numeroProcessoGerado, "Processo normal");
                        if(!filaNormal.contains(processoTmp)){
                            filaNormal.offer(processoTmp);
                            System.out.println(processoTmp);
                        }
                    }
                    break;
            }
        }
    }

    /***
     * Método estático que exibe processos existentes em fila
     * @param fila - contém uma fila normal ou uma fila prioritária
     * @param frase - frase ou texto a ser exibido no cabeçalho da exibição ou listagem
     */
    public static void exibirProcessosNaoAtendidos(Queue<Processo> fila, String frase){
        System.out.println(frase);
        System.out.println("Total de processos não atendidos: " + fila.size());
        for (Processo processo : fila) {
            System.out.println(processo);
        }
    }

    public static void main(String[] args) {
        Queue<Processo> filaPrioritaria = new LinkedList<>();
        Queue<Processo> filaNormal = new LinkedList<>();
        gerarProcessosEmFilas(filaPrioritaria, filaNormal, 10);
        exibirProcessosNaoAtendidos(filaPrioritaria, "Fila prioritária");
        exibirProcessosNaoAtendidos(filaNormal, "Fila normal");
    }
}