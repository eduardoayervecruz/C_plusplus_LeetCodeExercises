    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        bool valid;
        // Possible substrings have a lenght up to half of the string length
        for (int len = 1; len <= n / 2; ++len) {
            // Check if the lenght of the substring is multiple of the string
            if (n % len == 0) {
                std::string substring = s.substr(0, len);
                valid = true;
                // Check if the pattern is repeated
                for (int i = len; i < n; i += len) {
                    if (s.substr(i, len) != substring) {
                        valid = false;
                        break;
                    }
                }
                // Return statement only if valid is true, can't return
                // valid because return statement must be done in each loop
                if (valid) return true;
            }
            // If substring lenght is not a multiple, continue
        }
    
    return false;
    }
