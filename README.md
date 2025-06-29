# SlotMachine
*First project pclp1*

Gigel is passionate about gambling and is in quite a difficult financial situation. He would like to know what he needs to do to win a considerable amount of money. He heard 
that 99% of players stop right before they win, so he has decided not to be part of that statistic. With this in mind, he came to you with the following idea: a slot machine 
simulator. He also mentioned that he doesn't trust the demo versions on various betting apps, as they seem to offer suspiciously frequent winnings.

There will be a number **N** of rows and **M** columns, representing all the symbols present in this simulator; the columns can move independently from one another, and the 
symbols in a column always maintain their relative positions with respect to each other (i.e., [1, 2, 3, 4] can become [3, 4, 1, 2], but not [1, 3, 2, 4]), following a 
rotational movement of the columns. There will be at most 10 distinct symbols, which we will conveniently number from 0 to 9 (each digit is essentially a coded symbol).

As mentioned above, not all the symbols in the matrix can form winning combinations at a given time — only those located within a predefined frame. This frame is a 3 x M 
rectangle (i.e., it spans the entire width of the matrix and includes 3 symbols from each column). We consider this frame to be at the very “top end” of the matrix, meaning it 
always includes the first 3 rows of the matrix and cannot be moved. Here's an illustrative example:

    N = 8, M = 4;
    1 2 3 4
    1 6 2 5
    3 4 2 2
    9 0 1 3
    5 5 5 2
    1 7 8 8
    3 3 6 5
    7 7 7 7

The frame contains the first 3 rows, meaning the symbols:

    1 2 3 4
    1 6 2 5
    3 4 2 2

TODO

Task1

Gigel has a number of features he would like this simulator to have, as follows:

**Task 1. Spin the... pixels? (10p)**
  The goal is to rotate a specified column. For example, if we have a matrix with 5 rows and 3 columns, and we want to rotate the second column by 3 positions, the intended 
  operation means shifting the symbols in the second column 3 positions downward, while keeping the first and last columns unchanged.

  The shifting is circular, from top to bottom, and the symbols that “fall off” the bottom of the matrix are moved to the top.

  Illustrative example:

    N = 5, M = 3;
    1 2 3
    4 5 6
    7 8 9
    0 1 2
    3 4 5
    c = 1, r = 3 // indexing starts at 0

**Task 2. The game might be rigged, but the gains are real (30 points)**

  Given a configuration of a matrix, the goal is to find all winning combinations. A winning combination is a sequence of symbols located within the grid that satisfies the 
  following rules:

  On a row, there are at least 3 identical symbols; note: for any particular row, only the longest sequence of identical symbols is considered.

  On a diagonal, there are 3 identical symbols (for example, the symbols at positions (1, 1), (2, 2), and (3, 3) are identical, but the sequence doesn't necessarily have to 
  start from column 1). You must consider both "main" diagonals and "secondary" diagonals, so both of the forms:

  [(1, i), (2, i + 1), (3, i + 2)] (main diagonals)

  [(3, i), (2, i + 1), (1, i + 2)] (secondary diagonals)

  Note: if two such diagonals form an "X", meaning they intersect at the middle symbol, this intersection is counted as a single winning combination, not two.

  The requirement is to compute the number of such winning combinations.

  Additionally, you must calculate the score obtained by Gigel for this configuration. The score is defined as the sum of the values of all unit winning combinations found 
  in the grid. These are the associated values:

    1.A winning row with K identical symbols has a value of K, where K is any number greater than or equal to 3

    2.A winning diagonal of 3 identical symbols has a value of 7

    3.A winning "X" has a value of 21

  There are also some bonuses that apply to the score calculation:

    1.For any winning combination as described above, if the symbol in the combination is 7, then the value of the combination is doubled

    2.If the grid contains at most 4 distinct symbols, an additional 15 points are added to the score

    3.If the grid contains at most 2 distinct symbols, an additional 100 points are added to the score; these two bonuses do not stack

  You are asked to calculate the final score obtained by Gigel.

**Task 3. All in. (15 points)**
  Note: It is preferable to implement the first two tasks before attempting this one.

  Faced with the real slot machine, Gigel wants to keep track of his "winnings," so he’s asking for your help. You will first receive the dimensions of the matrix, followed  
  by the matrix itself, and then a series of operations in the form of pairs (column, rotation).

  At the end, you must display the total score obtained by Gigel in the final configuration of the matrix, summing all the scores obtained at each intermediate stage.

**Task 4. So close! (15 points)**
  At some point, Gigel wonders what he could achieve if he were allowed to change a single symbol in the matrix. He asks you, the programmers, to implement this   
  functionality. More precisely, he wants to replace a symbol at a certain position with another symbol of his choosing and obtain the maximum possible score as a result of 
  this change.

  You are required to output the theoretical maximum score that Gigel could have earned under these conditions.
  
**Task 5. What if? ... (20 points)**
  After daydreaming about fabulous winnings, Gigel considers another possibility: since he can't change the values already recorded on the machine, he imagines that he   
  could rotate any two columns, however he wants, in order to get the maximum score.

  Therefore, he asks you how he could obtain the maximum score by performing two column rotations (each by an arbitrary number of positions).

  You are required to compute the maximum possible winnings Gigel could obtain after two such rotations.

**Task 6 (Bonus). 99% of gamblers quit right before they win (20 points)**
  As Gigel hallucinates about spectacular spins, he realizes that he’s out of money. Since his last cash is reserved for a shawarma, he begins imagining a new game—one that 
  doesn’t require losing more money.

  You are required to implement this new game, which follows the rules below:

    1.The game takes place within the grid of the slot machine.
    
    2.The goal is to start from the top-left corner of the grid and reach the bottom-right corner, following a path with the minimum total cost.
    
    3.Moving to each symbol has an associated cost, and the total cost of a path is the sum of the costs of all the symbols traversed.
    
    4.A valid move is a step in one of the four cardinal directions: up, down, left, or right.
    
    5.The player cannot leave the grid.
    
    6.The cost of stepping into a cell is the absolute difference between the symbol's value and the value of the starting symbol (i.e., the symbol at the top-left corner).
    
    7.You are asked to compute the minimum cost path from the top-left to the bottom-right of the grid.
    
    8.Gigel bets he can find this cost faster than you—if only he weren’t having a bit of financial trouble.
