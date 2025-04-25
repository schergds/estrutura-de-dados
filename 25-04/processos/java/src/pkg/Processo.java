package pkg;

import java.util.Objects;

public class Processo {

    private int id;
    private String descricao;

    /***
     * Construtor do processo
     * @param id - inteiro com número aleatório entre 1 e 1000
     * @param descricao - explicação do processo
     */

    public Processo(int id, String descricao) {
        this.id = id;
        this.descricao = descricao;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    @Override
    public String toString() {
        return "Processo{" +
                "id=" + id +
                ", descricao='" + descricao + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Processo processo = (Processo) o;
        return id == processo.id;
    }

    @Override
    public int hashCode() {
        return Objects.hashCode(id);
    }
}
