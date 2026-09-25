class Solution {
public:
    int i = 0;
    set<string> parse(string expression) {
        set<string> result;
        if (expression[i] == '{') {
            i++;
            set<string> current;
            while (expression[i] != '}') {
                set<string> temp = parse(expression);
                if (current.empty()) {
                    current = temp;
                } else {
                    set<string> combined;
                    for (auto& s1 : current) {
                        for (auto& s2 : temp) {
                            combined.insert(s1 + s2);
                        }
                    }
                   current=combined;
                }
                
                if (expression[i] == ',') {
                    for (auto& s : current) {
                        result.insert(s);
                    }

                    current.clear();
                    i++;
                }
            }
            for (auto& s : current) {
                result.insert(s);
            }
            i++;
        } else {
            result.insert(string(1, expression[i]));
            i++;
        }
        return result;
    }
    vector<string> braceExpansionII(string expression) {
        set<string> result;
        while (i < expression.size()) {
            set<string> temp = parse(expression);
            if (result.empty()) {
                result = temp;
            } else {
                set<string> combined;
                for (auto& s1 : result) {
                    for (auto& s2 : temp) {
                        combined.insert(s1 + s2);
                    }
                }
                result = combined;
            }
            if (i < expression.size() && expression[i] == ',') {
                i++;
            }
        }
        return vector<string>(result.begin(), result.end());
    }
};