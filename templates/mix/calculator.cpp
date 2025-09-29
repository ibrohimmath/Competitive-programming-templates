struct StringCalc {
    std::stack<int> nums;
    std::stack<char> ops;

    bool is_number(char c) { return '0' <= c && c <= '9'; }
    bool is_op(char c) { return c == '+' || c == '-' || c == '*' || c == '/'; }

    int prior(char c) {
        if (c == '+' || c == '-') return 1;
        if (c == '*' || c == '/') return 2;
        return 0;
    }

    int apply(char op) {
        if (nums.size() < 2) throw std::runtime_error("invalid expression");
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
        return 0;
    }

    int calculate(const std::string &expr) {
        for (size_t i = 0; i < expr.size(); i++) {
            if (expr[i] == ' ') continue; // skip spaces

            if (is_number(expr[i])) {
                int num = 0;
                size_t j = i;
                while (j < expr.size() && is_number(expr[j])) {
                    num = num * 10 + (expr[j] - '0');
                    j++;
                }
                nums.push(num);
                i = j - 1;
            } else if (expr[i] == '(') {
                ops.push('(');
            } else if (is_op(expr[i])) {
                while (!ops.empty() && prior(ops.top()) >= prior(expr[i])) {
                    int val = apply(ops.top()); ops.pop();
                    nums.push(val);
                }
                ops.push(expr[i]);
            } else if (expr[i] == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    int val = apply(ops.top()); ops.pop();
                    nums.push(val);
                }
                if (!ops.empty()) ops.pop(); // pop '('
            } else {
                throw std::runtime_error("invalid character");
            }
        }
        while (!ops.empty()) {
            int val = apply(ops.top()); ops.pop();
            nums.push(val);
        }
        return nums.top();
    }
};
