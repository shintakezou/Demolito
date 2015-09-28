#pragma once
#include "bitboard.h"
#include "types.h"

namespace zobrist {

class PRNG {
	uint64_t a, b, c, d;
public:
	PRNG() { init(); }
	void init(uint64_t seed = 0);
	uint64_t rand();
};

class History {
	uint64_t keys[MAX_GAME_PLY];
	int idx;
public:
	void clear() { idx = 0; }
	void push(uint64_t key);
	void pop();
	bool repetition(int rule50) const;
};

void init();

uint64_t key(int color, int piece, int sq);
uint64_t castling(bitboard_t castlableRooks);
uint64_t en_passant(int sq);
uint64_t turn();

}	// namespace zobrist
