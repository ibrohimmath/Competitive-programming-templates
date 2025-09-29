namespace IO {
    void init(bool fast = true) {
        if (fast) {
            // std::cin.tie(0)->sync_with_stdio(0);
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
        }
    }

    template <typename... Args>
    void read(Args&... args) {
        ((std::cin >> args), ...);
    }
    
    template <typename... Args>
    void writeln(Args... args) {
        ((std::cout << args << ' '), ...);
        std::cout << '\n';
    }
}