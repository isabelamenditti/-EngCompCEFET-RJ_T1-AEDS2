# -EngCompCEFET-RJ_T1-AEDS2
All the projects and assignments I completed during college.

beecrowd | 1148 - Países em Guerra

No ano 2050, após diversas tentativas da ONU de manter a paz no mundo, explode a terceira guerra mundial. Segredos industriais, comerciais e militares obrigaram todos os países a utilizar serviços de espionagem extremamente sofisticados, de forma que em cada cidade do mundo há ao menos um espião de cada país. Esses espiões precisam se comunicar com outros espiões, com informantes e mesmo com as suas centrais durante as suas ações. Infelizmente não existe uma forma segura de um espião se comunicar em um período de guerra, então as mensagens são sempre enviadas em código para que somente o destinatário consiga ler a mensagem e entender o seu significado.

Os espiões utilizam o unico serviço que funciona no período de guerra, os correios. Cada cidade possui uma agência postal onde as cartas são enviadas. As cartas podem ser enviadas diretamente ao seu destino ou a outras agências postais, até que a carta chegue à agência postal da cidade de destino, se isso for possível.

Uma agência postal na cidade A pode enviar diretamente uma carta impressa para a agência postal da cidade B se houver um acordo de envio de cartas, que determina o tempo, em horas, que uma carta leva para chegar da cidade A à cidade B (e não necessariamente o contrário). Se não houver um acordo entre as agências A e B, a agência A pode tentar enviar a carta a quantas agências for necessário para que a carta chegue ao seu destino, se isso for possível.

Algumas agências são interligadas por meios eletrônicos de comunicação, como satélites e fibras ópticas. Antes da guerra, essas ligações atingiam todas as agências, fazendo com que uma carta fosse enviada de forma instantânea, mas durante o período de hostilidades cada país passou a controlar a comunicação eletrônica e uma agência somente pode enviar uma carta a outra agência por meio eletrônico (ou seja, instantaneamente) se ela estiver no mesmo país. Duas agências, A e B, estão no mesmo país se houver uma forma de uma carta impressa enviada de uma das agências ser entregue na outra agência.

O serviço de espionagem do seu país conseguiu obter o conteúdo de todos os acordos de envios de mensagens existentes no mundo e deseja descobrir o tempo mínimo para se enviar uma carta entre diversos pares de cidades. Você seria capaz de ajudá-lo?
Entrada
A entrada contém vários casos de teste. A primeira linha de cada caso de teste contém dois inteiros separados por um espaço, N (1 ≤ N ≤ 500) e E (0 ≤ E ≤ N2), indicando o número de cidades (numeradas de 1 a N) e de acordos de envio de mensagens, respectivamente. Seguem-se, então, E linhas, cada uma com três inteiros separados por espaços, X, Y e H (1 ≤ X, Y ≤ N, 1 ≤ H ≤ 1000), indicando que existe um acordo para enviar uma carta impressa da cidade X à cidade Y , e que tal carta será entregue em H horas.

Em seguida, haverá uma linha com um inteiro K (0 ≤ K ≤ 100), o número de consultas. Finalmente, virão K linhas, cada uma representando uma consulta e contendo dois inteiros separados por um espaço, O e D (1 ≤ O, D ≤ N). Você deve determinar o tempo mínimo para se enviar uma carta da cidade O à cidade D. A entrada termina quando N = E = 0.
Saída
Para cada caso de teste da entrada seu programa deve produzir K linhas na saída. A I-ésima linha deve conter um inteiro M , o tempo mínimo, em horas, para se enviar uma carta na I-ésima consulta. Se não houver meio de comunicação entre as cidades da consulta, você deve imprimir ”Nao e possivel entregar a carta”(sem acentos).

Imprima uma linha em branco após cada caso de teste.
_________________________________________________________________________________________________________________________________________

beecrowd | 1152 - Estradas Escuras

Nestes dias se pensa muito em economia, mesmo em Byteland. Para reduzir custos operacionais, o governo de Byteland decidiu otimizar a iluminação das estradas. Até agora, todas as rotas eram iluminadas durante toda noite, o que custava 1 Dólar Byteland por metro a cada dia. Para economizar, eles decidiram não iluminar mais todas as estradas e desligar a iluminação de algumas delas. Para ter certeza que os habitantes de Byteland continuem a se sentirem seguros, eles querem otimizar o sistema de tal forma que após desligar a iluminação de algumas estradas à noite, sempre existirá algum caminho iluminado de qualquer junção de Byteland para qualquer outra junção.

Qual é a quantidade máxima de dinheiro que o governo de Byteland pode economizar, sem fazer os seus habitantes sentirem-se inseguros?

Entrada
A entrada contém vários casos de teste. Cada caso de teste inicia com dois números m (1 ≤ m ≤ 200000) e n (m-1 ≤ n ≤ 200000), que são o número de junções de Byteland e o número de estradas em Byteland, respectivamente. Seguem n conjuntos de três valores inteiros, x, y e z, especificando qual será a estrada bidirecional entre x e y com z metros (0 ≤ x, y < m e x ≠ y).

A entrada termina com m=n=0. O grafo especificado em cada caso de teste é conectado. O tamanho total de todas as estradas em cada caso de teste é menor do que 231.

Saída
Para cada caso de teste imprima uma linha contendo a máxima quantidade diária de dólares de Byteland que o governo pode economizar.
