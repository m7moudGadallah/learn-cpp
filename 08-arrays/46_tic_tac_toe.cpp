#include <iostream>
#include <vector>
using namespace std;

void init_board(vector<vector<char>>& board, char symbol) {
    for (auto& row : board)
        fill(row.begin(), row.end(), symbol);
}

void display_board(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) cout << cell;
        cout << '\n';
    }
}

bool check_row(const vector<vector<char>>& board, int row, char empty) {
    char first = board[row][0];
    if (first == empty) return false;
    for (char cell : board[row])
        if (cell != first) return false;
    return true;
}

bool check_col(const vector<vector<char>>& board, int col, char empty) {
    char first = board[0][col];
    if (first == empty) return false;
    for (int r = 0; r < board.size(); r++)
        if (board[r][col] != first) return false;
    return true;
}

bool check_main_diag(const vector<vector<char>>& board, char empty) {
    char first = board[0][0];
    if (first == empty) return false;
    for (int i = 0; i < board.size(); i++)
        if (board[i][i] != first) return false;
    return true;
}

bool check_sec_diag(const vector<vector<char>>& board, char empty) {
    int n = board.size();
    char first = board[0][n - 1];
    if (first == empty) return false;
    for (int i = 0; i < n; i++)
        if (board[i][n - 1 - i] != first) return false;
    return true;
}

bool is_game_over(const vector<vector<char>>& board, char empty, int r, int c) {
    int n = board.size();
    return check_row(board, r, empty)
        || check_col(board, c, empty)
        || (r == c && check_main_diag(board, empty))
        || (r + c == n - 1 && check_sec_diag(board, empty));
}

int main() {
    const string PLAYER_SYMBOL = "xo";
    const char EMPTY = '.';
    bool turn = false;

    int n;
    cout << "Enter board size: ";
    cin >> n;

    vector<vector<char>> board(n, vector<char>(n, EMPTY));

    int moves = 0, max_moves = n * n;
    while (moves < max_moves) {
        int r, c;
        cout << "Player " << PLAYER_SYMBOL[turn] << " turn. Enter (r c): ";
        cin >> r >> c;
        --r, --c;

        if (r < 0 || r >= n || c < 0 || c >= n || board[r][c] != EMPTY) {
            cout << "Invalid input. Try again.\n";
            continue;
        }

        board[r][c] = PLAYER_SYMBOL[turn];
        display_board(board);

        if (is_game_over(board, EMPTY, r, c)) {
            cout << "Player " << PLAYER_SYMBOL[turn] << " won!\n";
            return 0;
        }

        turn = !turn;
        ++moves;
    }

    cout << "It's a draw!\n";
    return 0;
}
