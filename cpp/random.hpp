// RANDOM
// Random <= 1e9
mt19937 mt(time(nullptr));

int random() {
    return mt();
}
