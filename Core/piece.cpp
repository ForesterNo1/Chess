#include "piece.h"
#include <cmath>

// --- Pawn ---
Pawn::Pawn(Color color) : Piece(color) {}

char Pawn::getSymbol() const {
    return (color == Color::White) ? 'P' : 'p';
}

bool Pawn::isMoveLegal(int fromRow, int fromCol, int toRow, int toCol) const {
    int direction = (color == Color::White) ? -1 : 1;
    int rowDiff = toRow - fromRow;
    int colDiff = toCol - fromCol;

    
    if (std::abs(colDiff) == 1 && rowDiff == direction)
        return true;

    if (colDiff == 0 && rowDiff == direction)
        return true;

    if (colDiff == 0) {
        if ((color == Color::White && fromRow == 6 && toRow == 4) ||
            (color == Color::Black && fromRow == 1 && toRow == 3))
            return true;
    }

    return false;
}


// --- Knight ---
Knight::Knight(Color color) : Piece(color) {}

char Knight::getSymbol() const {
    return (color == Color::White) ? 'N' : 'n';
}

bool Knight::isMoveLegal(int fromRow, int fromCol, int toRow, int toCol) const {
    int dr = std::abs(fromRow - toRow);
    int dc = std::abs(fromCol - toCol);
    return (dr == 2 && dc == 1) || (dr == 1 && dc == 2);
}

// --- Bishop ---
Bishop::Bishop(Color color) : Piece(color) {}

char Bishop::getSymbol() const {
    return (color == Color::White) ? 'B' : 'b';
}

bool Bishop::isMoveLegal(int fromRow, int fromCol, int toRow, int toCol) const {
    return std::abs(fromRow - toRow) == std::abs(fromCol - toCol);
}

// --- Rook ---
Rook::Rook(Color color) : Piece(color) {}

char Rook::getSymbol() const {
    return (color == Color::White) ? 'R' : 'r';
}

bool Rook::isMoveLegal(int fromRow, int fromCol, int toRow, int toCol) const {
    return (fromRow == toRow || fromCol == toCol);
}

// --- Queen ---
Queen::Queen(Color color) : Piece(color) {}

char Queen::getSymbol() const {
    return (color == Color::White) ? 'Q' : 'q';
}

bool Queen::isMoveLegal(int fromRow, int fromCol, int toRow, int toCol) const {
    return (fromRow == toRow || fromCol == toCol ||
            std::abs(fromRow - toRow) == std::abs(fromCol - toCol));
}

// --- King ---
King::King(Color color) : Piece(color) {}

char King::getSymbol() const { return(color == Color::White) ? 'K' : 'k'; }

bool King::isMoveLegal(int fr, int fc, int tr, int tc)const {
    int dr = std::abs(fr - tr), dc = std::abs(fc - tc);
    if (dr <= 1 && dc <= 1) return true;
    if (dr == 0 && dc == 2) return true; // рокировка
    return false;
}
