// Copyright 2024 <Tudorica Radu Andrei>
#define symb_score_2 100
#define symb_score_4 15
#define diag_score 7
#define X_score 21
#define jackpot 7
#define symbol 9


int n_combos = 0;

int diag_s_win(int **a, int row, int col) {
    if (a[row][col] == a[row - 1][col + 1]) {
        if (a[row][col] == a[row - 2][col + 2]) {
        return 1;
        }
    }
    return 0;
}

int diag_p_win(int **a, int row, int col) {
    if (a[row][col] == a[row + 1][col + 1]) {
        if (a[row][col] == a[row + 2][col + 2]) {
            return 1;
        }
    }
    return 0;
}

int combo_win(int **a, int col) {
    int index = 0;

    for (int i = 0; i + 2 < col; i++) {
        const int row_diag_s = 2;
        const int row_diag_p = 0;
        if (diag_p_win(a, row_diag_p, i) && diag_s_win(a, row_diag_s, i)) {
            if (a[row_diag_p][i] == jackpot) {
                index += 2 * X_score;
            } else {
                index += X_score;
            }

            n_combos++;
        } else {
            if (diag_p_win(a, row_diag_p, i)) {
                if (a[row_diag_p][i] == jackpot) {
                    index += 2 * diag_score;
                } else {
                    index += diag_score;
                }

                n_combos++;
            }
            if (diag_s_win(a, row_diag_s, i)) {
                if (a[row_diag_s][i] == jackpot) {
                    index += 2*diag_score;
                } else {
                    index += diag_score;
                }

                n_combos++;
            }
        }
    }
    return index;
}

int line_win(int **a, int row, int col) {
    int seq = 0, length = 0, Max_lenght = 0, m_seq = 0;
    seq = a[row][0];
    length++;

    for (int j = 1; j < col; j++) {
        if (a[row][j] == seq) {
            length++;
        } else {
            if (length > Max_lenght) {
                m_seq = a[row][j - 1];
                Max_lenght = length;
            }
            seq = a[row][j];
            length = 1;
        }
    }
    if (length > Max_lenght) {
        Max_lenght = length;
        m_seq = seq;
    }

    if (m_seq == jackpot) {
        return 2 * Max_lenght;
    }

    return Max_lenght;
}

int diff_symbols(int **a, int row, int col) {
    int frecv[10] = {0}, index = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            frecv[a[i][j]] = 1;
        }
    }

    for (int i = 0; i <= symbol; i++) {
        index += frecv[i];
    }

    return index;
}

int task2(int **a, int col) {
    int score = 0;
    const int row_panel = 3;  // row = 3 pentru ca aceasta este cerinta
    int symb_score = diff_symbols(a, row_panel, col);

    if (symb_score <= 2) {
        score += symb_score_2;
    } else if (symb_score <= 4) {
        score += symb_score_4;
    }
    for (int i = 0; i < row_panel; i++) {
        int line_score = line_win(a, i, col);
        if (line_score >= 3) {
            n_combos++;
            score += line_score;
        }
    }
    score += combo_win(a, col);

    return score;
}
