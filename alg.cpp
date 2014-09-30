// Anagram.cpp
#include <iostream>

using namespace std;

const int NO_OF_CHARS = 100;

bool areAnagram(char *str1, char *str2) {
    // Create a count array and initialize all values as 0
    int count[NO_OF_CHARS] = {0};
    int i;

    // For each character in input strings, increment count in
    // the corresponding count array
    for (i = 0; str1[i] && str2[i];  i++) {
        count[str1[i] - '0']++;
        count[str2[i] - '0']--;
    }

    // If both strings are of different length. Removing this condition
    // will make the program fail for strings like "aaca" and "aca"
    if (str1[i] || str2[i]) {
        return false;
    }

    // See if there is any non-zero value in count array
    for (i = 0; i < NO_OF_CHARS; i++) {
        if (count[i]) {
            return false;
        }
    }
    return true;
}


// ArrayToBinayTree.cpp
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *arrayToTree(vector<int> &array, int i) {
    if (i >= array.size()) {
        return NULL;
    }
    TreeNode *root = new TreeNode(array[i]);
    root->left = arrayToTree(array, 2 * i + 1);
    root->right = arrayToTree(array, 2 * i + 2);
    return root;
}


// CommonCharacters.cpp
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int commonCharacters(vector<string> &strs) {
    if (strs.size() == 0 || strs.size() == 1) {
        return 0;
    }
    int dict[255] = { 0 };
    int charSet[255] = { 0 };
    int res = 0;
    for (int i = 0; i < strs[0].length(); ++i) {
        dict[strs[0][i]] += 1;
    }
    for (int i = 1; i < strs.size(); ++i) {
        for (int j = 0; j < strs[i].length(); ++j) {
            if (dict[strs[i][j]] > 0) {
                charSet[strs[i][j]] += 1;
            }
        }
    }
    for (int i = 0; i < 256; ++i) {
        if (charSet[i] == strs.size()) {
            res++;
        }
    }
    return res;
}

int main() {
    vector<string> strs;
    strs.push_back("aghkafgklt");
    strs.push_back("dfghako");
    strs.push_back("qwemnaarkf");
    cout << commonCharacters(strs) << endl;
    return 0;
}


// FindKthElementInArray.cpp
#include <iostream>

using namespace std;

const int MAX = 10000;
int A[MAX], N;

int partitions(int low, int high) {
    int p = low, r = high, x = A[r], i = p - 1;
    for(int j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            i = i + 1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}

int selection_algorithm(int left,int right,int kth) {
    for(;;) {
        int pivotIndex=partitions(left,right);          //Select the Pivot Between Left and Right
        int len=pivotIndex-left+1;
        if(kth == len) {
            return A[pivotIndex];
        } else if(kth<len) {
            right = pivotIndex - 1;
        } else {
            kth = kth - len;
            left = pivotIndex + 1;
        }
    }
}


// FlipBinayTree.cpp
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode * FlipTree (TreeNode *root) {
    if (!root) {
        return NULL;
    }
    // Working base condition
    if (!root->left && !root->right) {
        return root;
    }
    TreeNode *newRoot = FlipTree(root->left);
    root->left->left = root->right;
    root->left->right = root;
    root->left = NULL;
    root->right = NULL;
    return newRoot;
}


// ImplementQueueWithStack.cpp
#include <iostream>
#include <stack>

using namespace std;

template <typename T> class CQueue {
public:
    CQueue(void) {}
    ~CQueue(void) {}
    void enqueue(const T& element) {
        stack1.push(element);
    }
    T dequeue() {
        if(stack2.size() <= 0) {
            while(stack1.size() > 0) {
                T& data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }
        if(stack2.size() == 0) {
            throw new exception();
        }
        T head = stack2.top();
        stack2.pop();
        return head;
    }
private:
    stack<T> stack1;
    stack<T> stack2;
};


// Isomorphic.cpp
#include <iostream>
#include <unordered_map>

bool isIsomorphic(std::string first, std::string second) {
    if (first.length() != second.length()) {
        return false;
    }

    // One map to keep track of the characters in the
    // first string to the second string, another to keep
    // track of the characters in the second string to the first
    std::unordered_map<char, char> iso1;
    std::unordered_map<char, char> iso2;

    for (int i = 0; i < first.length(); i++) {
        char c1 = first[i];
        char c2 = second[i];

        // If the character already exists in the map,
        // check to make sure it's mapping to the same
        // character
        if (iso1.find(c1) != std::map::end) {
            if (iso1.at(c1) != c2) {
                return false;
            }
        } else {
            iso1.insert(std::pair<char, char>(c1, c2));
        }
        if (iso2.find(c2) != std::map::end) {
            if (iso2.at(c2) != c1) {
                return false;
            }
        } else {
            iso2.insert(std::pair<char, char>(c2, c1));
        }
    }
    return true;
}


// LogBase2IntergralPart.cpp
#include <iostream>

using namespace std;

int log2(int n) {
    int res = 0;
    while (n >>= 1) {
        res++;
    }
    return res;
}

int main() {
    cout << log2(1) << endl;
    cout << log2(2) << endl;
    cout << log2(4) << endl;
    cout << log2(5) << endl;
    cout << log2(6) << endl;
    cout << log2(10) << endl;
    cout << log2(100) << endl;
    return 0;
}


// LowestCommonAncestor.cpp
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *getLCA(TreeNode *root, TreeNode *node1, TreeNode *node2) {
    if (!root || !node1 || !node2) {
        return NULL;
    }
    if (root == node1 || root == node2) {
        return root;
    }
    TreeNode *left = getLCA(root->left, node1, node2);
    TreeNode *right = getLCA(root->right, node1, node2);
    if (!left) {
        return right;
    } else if (!right) {
        return left;
    } else {
        return root;
    }
}


// MaximumProductSubarray.cpp
#include <iostream>

using namespace std;

int maxSubarrayProduct(int arr[], int n) {
    // max positive product ending at the current position
    int max_ending_here = 1;

    // min negative product ending at the current position
    int min_ending_here = 1;

    // Initialize overall max product
    int max_so_far = 1;

    /* Traverse throught the array. Following values are maintained after the ith iteration:
       max_ending_here is always 1 or some positive product ending with arr[i]
       min_ending_here is always 1 or some negative product ending with arr[i] */
    for (int i = 0; i < n; i++) {
        /* If this element is positive, update max_ending_here. Update
           min_ending_here only if min_ending_here is negative */
        if (arr[i] > 0) {
            max_ending_here = max_ending_here*arr[i];
            min_ending_here = min (min_ending_here * arr[i], 1);
        }

        /* If this element is 0, then the maximum product cannot
           end here, make both max_ending_here and min_ending_here 0
Assumption: Output is alway greater than or equal to 1. */
        else if (arr[i] == 0) {
            max_ending_here = 1;
            min_ending_here = 1;
        }

        /* If element is negative. This is tricky
           max_ending_here can either be 1 or positive. min_ending_here can either be 1
           or negative.
           next min_ending_here will always be prev. max_ending_here * arr[i]
           next max_ending_here will be 1 if prev min_ending_here is 1, otherwise
           next max_ending_here will be prev min_ending_here * arr[i] */
        else {
            int temp = max_ending_here;
            max_ending_here = max (min_ending_here * arr[i], 1);
            min_ending_here = temp * arr[i];
        }

        // update max_so_far, if needed
        if (max_so_far <  max_ending_here) {
            max_so_far  =  max_ending_here;
        }
    }
    return max_so_far;
}


// MergeSort.cpp
#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(const vector<int>& left, const vector<int>& right) {
    // Fill the resultant vector with sorted results from both vectors
    vector<int> result;
    unsigned left_it = 0, right_it = 0;

    while(left_it < left.size() && right_it < right.size()) {
        // If the left value is smaller than the right it goes next
        // into the resultant vector
        if(left[left_it] < right[right_it]) {
            result.push_back(left[left_it]);
            left_it++;
        } else {
            result.push_back(right[right_it]);
            right_it++;
        }
    }

    // Push the remaining data from both vectors onto the resultant
    while(left_it < left.size()) {
        result.push_back(left[left_it]);
        left_it++;
    }

    while(right_it < right.size()) {
        result.push_back(right[right_it]);
        right_it++;
    }

    return result;
}

vector<int> merge_sort(vector<int>& vec) {
    // Termination condition: List is completely sorted if it
    // only contains a single element.
    if(vec.size() == 1) {
        return vec;
    }

    // Determine the location of the middle element in the vector
    std::vector<int>::iterator middle = vec.begin() + (vec.size() / 2);

    vector<int> left(vec.begin(), middle);
    vector<int> right(middle, vec.end());

    // Perform a merge sort on the two smaller vectors
    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
}


// MoreThanHalf.cpp

// NumOfCommonChars.java
public int getNumOfCommonChars(String[] inputs) {
    // Return 0 if null / empty input or only one string is provided
    if(inputs == null || inputs.length < 2) {
        return 0;
    } else {
        //create an int array to hold # times character appears 
        int[] charCounts = new int[256];
        for(String input : inputs) {
            Set<Character> uniqueCharSet = new HashSet<Character>();
            for(int i=0; i < input.length(); i++) {
                char ch = input.charAt(i);
                if (!uniqueCharSet.contains(ch)) {
                    uniqueCharSet.add(ch);
                    charCounts[(int) ch] += 1;
                }
            }
        }

        int commonCharCount = 0;
        for (int i=0; i < 256; i++) {
            if (charCounts[i] == inputs.length()) {
                commonCharCount++;
            }
        }

        return commonCharCount;
    }
}


// ParseIp.cpp
#include <fstream>
#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;

typedef unsigned int uint;

uint ip2num(const char* buf) {
  uint res = 0, b = 0;
  for (; *buf;) {
    char c = *buf++;
    if (c == '.') {
      res = (res << 8) + b;
      b = 0;
    } else if (isdigit(c)) {
      b = b * 10 + (c - '0');
    } else {
      return (res << 8) + b;
    }
  }
  return (res << 8) + b;
}


// RecursiveSum.cpp
#include <iostream>
#include <vector>

using namespace std;

int sum(vector<int> array, int stopIndex) {
   if (array.size() == 0 ||
       stopIndex >= array.size()) // so we don't try to access an index that doesn't exist
   {
      return 0;
   }
   if (stopIndex == 0) {
      return array[stopIndex];
   } else {
      return array[stopIndex] + sum(array, stopIndex - 1);
   }
}


// ReverseLinkedList.cpp
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverse(ListNode *head) {
    ListNode *prev = NULL, *cur = head;
    while(cur) {
        ListNode *tmp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tmp;
    }
    return prev;
}


// SelfExcludeMultiply.cpp
#include <iostream>
#include <vector>

using namespace std;

vector<int> selfExcludeMultiply(vector<int> &input) {
    int zero = 0, prod = 1;
    vector<int> res(input.size());
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == 0) {
            zero++;
            if (zero == 2) {
                return res;
            }
        } else {
            prod *= input[i];
        }
    }
    for (int i = 0; i < input.size(); ++i) {
        if (input[i] == 0) {
            res[i] = prod;
        } else {
            res[i] = prod / input[i];
        }
    }
    return res;
}

int main() {
    vector<int> input = { 1,2,0,4,5,0,7,8 };
    vector<int> output = selfExcludeMultiply(input);
    for (auto i : output) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}


// WordDistanceFinder.java
public class WordDistanceFinder {

    private String[] text;

    public WordDistanceFinder(String[] list) {
        this.text = list;
    }

    /**
     * Brute Force method to find the distance between two words.
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     *
     */
    public int findDistance(String a, String b) {
        int size = text.length;
        int distance = -1; //distance between words to be sent as output when they are not present in the given text

        /* When both words are same then distance should be zero*/
        if(a == b) {
            return 0;
        }
        for(int i = 0; i < size; i++) {
            if(text[i] == a || text[i] == b) {
                boolean temp = text[i] == a;
                b = temp ? b : a; //Search for b if a is found or search for a
                distance++; //reset distance from -1 to 0

                while(i < (size - 1) && text[i] != b) {
                    i++;
                    distance++;
                    if(text[i] == b) {
                        return distance;
                    }
                }
            }
        }

        return distance;
    }
}


