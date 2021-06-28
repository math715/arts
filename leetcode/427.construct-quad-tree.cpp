/*
 * @lc app=leetcode id=427 lang=cpp
 *
 * [427] Construct Quad Tree
 */

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int M = grid.size();
        if (M == 0) return nullptr;
        if (M == 1) {
            Node *root = new Node(grid[0][0], true);
            return root;
        } else {
            return construct(grid, 0, 0, M);
        }
        
    }

    Node *construct(vector<vector<int>>&grid, const int idx, const int idy, const int size) {
        if (size == 1) {
            Node *root = new Node(grid[0][0], true);
        }
        int M = grid.size();
        bool flag = true;
        int value = grid[idx][idy];
        for (int i = 0; i < size; ++i ) {
            for (int j = 0; j < size; ++j) {
                if (grid[i + idx][j + idy] != value) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
              Node *node = new Node(value, true);
              return node;
        } else {          
            int n = size/2;
            Node* _topLeft = construct(grid, idx, idy, n);
            Node* _topRight = construct(grid, idx, idy + n,n);
            Node* _bottomLeft = construct(grid, idx  +n, idy, n);
            Node* _bottomRight = construct(grid, idx + n, idy + n, n); 
            Node *node = new Node(true, false, _topLeft, _topRight, _bottomLeft, _bottomRight);
            return node;
        }
        
    }
};
// @lc code=end

