// RANDOM
// Random <= 1e9

auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed);


int random() {
    return mt();
}
