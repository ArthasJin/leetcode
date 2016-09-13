// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    char buffer4[4] = { 0 };
    int i4 = 0, n4 = 0;
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int i = 0;
        while (i < n && (i4 < n4 || (i4 = 0) < (n4 = read4(buffer4)))) {
            buf[i++] = buffer4[i4++];
        }
        return i;
    }
};

