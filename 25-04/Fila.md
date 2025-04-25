- físicas
- abstratas
    - listas, dicionários, listas de listas, listas de dicionários, listas de objetos, hashset
    - orientação a objetos
        - reescrita de operações/métodos
            - toString(), ToString(), __str__, __repr__
            - equals(), Equals(), __eq__
            - hashCode(), GetHashCode(), __hash__
    - filas (Queue) - classe abstrata -> esqueleto com atributos e métodos... só que não instancia objetos
        - FIFO - First In, First Out
            - operações clássicas:
                - inserir no final/cauda -> add
                - remover início/cabeça -> remove
            - operações herdadas:
                - size
                - contains
                - indexOf???

Cenário de aplicação de filas:
    1) Gerenciar processos -> id, descrição
	    - classe Processo
		    atributos -> id, descrição
		    métodos -> toString
    2) Processos têm prioridades:
        - Processos com id entre 1 e 500: alta prioridade
        - Processos com id entre 501 e 1000: baixa prioridade
    3) Há duas filas:
        - Prioritária (ids 1 a 500)
        - Normal (ids 501 a 1000)
    4) Dinâmica:
        - Um número aleatório será gerado entre 0 e 1000
            - Se for 0 -> atender/remover a cabeça da fila de prioridade
                - Tratar caso a fila esteja vazia
			- 500 -> atender/remover a cabeça da fila normal - tratar quando vazia
			- demais números seguem a dinâmica acima -> controle de replicados
		- a dinâmica deve repetir 10000 vezes
		- exibir as filas ao final, com os processos não atendidos (mostrando contadores)