namespace _25_04_cs;

using System;
public class Processo
{
    public int Id { get; set; }
    public string Descricao { get; set; }

    // Construtor do processo
    public Processo(int id, string descricao)
    {
        Id = id;
        Descricao = descricao;
    }

    public override string ToString()
    {
        return $"Processo{{ id={Id}, descricao='{Descricao}' }}";
    }

    public override bool Equals(object obj)
    {
        if (obj == null || GetType() != obj.GetType()) return false;
        Processo processo = (Processo)obj;
        return Id == processo.Id;
    }

    public override int GetHashCode()
    {
        return Id.GetHashCode();
    }
}
