namespace _25_04_cs;

using System;
using System.Collections.Generic;

public class MainClass
{
    // Método responsável por gerar processos aleatórios entre 1 a 1000,
    // distribuindo em duas filas
    public static void GerarProcessosEmFilas(Queue<Processo> filaPrioritaria, Queue<Processo> filaNormal, int quantidadeProcessos)
    {
        Random random = new Random();
        int numeroProcessoGerado;

        for (int i = 0; i < quantidadeProcessos; i++)
        {
            numeroProcessoGerado = random.Next(0, 1001);  // Gera número entre 0 e 1000

            switch (numeroProcessoGerado)
            {
                case 0:
                    Console.WriteLine("Atendendo: " + filaPrioritaria.Dequeue());
                    break;

                case 500:
                    Console.WriteLine("Atendendo: " + filaNormal.Dequeue());
                    break;

                default:
                    if (numeroProcessoGerado < 500)
                    {
                        Processo processoTmp = new Processo(numeroProcessoGerado, "Processo de alta prioridade");
                        if (!filaPrioritaria.Contains(processoTmp))
                        {
                            filaPrioritaria.Enqueue(processoTmp);
                            Console.WriteLine(processoTmp);
                        }
                    }
                    else
                    {
                        Processo processoTmp = new Processo(numeroProcessoGerado, "Processo normal");
                        if (!filaNormal.Contains(processoTmp))
                        {
                            filaNormal.Enqueue(processoTmp);
                            Console.WriteLine(processoTmp);
                        }
                    }
                    break;
            }
        }
    }

    // Método que exibe os processos não atendidos nas filas
    public static void ExibirProcessosNaoAtendidos(Queue<Processo> fila, string frase)
    {
        Console.WriteLine(frase);
        Console.WriteLine("Total de processos não atendidos: " + fila.Count);
        foreach (Processo processo in fila)
        {
            Console.WriteLine(processo);
        }
    }

    public static void Main(string[] args)
    {
        Queue<Processo> filaPrioritaria = new Queue<Processo>();
        Queue<Processo> filaNormal = new Queue<Processo>();

        GerarProcessosEmFilas(filaPrioritaria, filaNormal, 10);
        ExibirProcessosNaoAtendidos(filaPrioritaria, "Fila prioritária");
        ExibirProcessosNaoAtendidos(filaNormal, "Fila normal");
    }
}
