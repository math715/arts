/*
 * @lc app=leetcode id=432 lang=cpp
 *
 * [432] All O`one Data Structure
 */

// @lc code=start
class AllOne {
public:
      struct Node {
    std::unordered_set<std::string> values;
    int count = 0;
    std::shared_ptr<Node> prev;
    std::shared_ptr<Node> next;
  };
  using NodePtr = std::shared_ptr<Node>;
  /** Initialize your data structure here. */
  AllOne() {
    root.reset(new Node());
    root->prev = root;
    root->next = root;
  }
 
  /** Inserts a new key <Key> with value 1. Or increments an existing key by 1.
   */
  void inc(string key) {
    if (table.find(key) == table.end()) {
      if (root->prev == root) {
        NodePtr node(new Node());
        node->values.insert(key);
        node->count = 1;
        node->next = root;
        node->prev = root;
        root->prev = node;
        root->next = node;
        table[key] = node;
      } else {
        auto p = root->prev;
        if (p->count == 1) {
          p->values.insert(key);
          table[key] = p;
        } else {
          NodePtr node(new Node());
          node->values.insert(key);
          node->count = 1;
          p->next = node;
          root->prev = node;
          node->next = root;
          node->prev = p;
          table[key] = node;
        }
      }
    } else {
      auto node = table[key];
      int count = node->count + 1;
      if (node->values.size() == 1) {
        if (node->prev->count == count) {
          node->prev->values.insert(key);
          node->prev->next = node->next;
          node->next->prev = node->prev;
          table[key] = node->prev;
        } else {
          node->count = count;
        }
      } else {
        node->values.erase(key);
        if (node->prev == root) {
          NodePtr n(new Node());
          n->count = count;
          n->values.insert(key);
          root->next = n;
          n->prev = root;
          n->next = node;
          node->prev = n;
          table[key] = n;
        } else {
          if (node->prev->count == count) {
            node->prev->values.insert(key);
            table[key] = node->prev;
          } else {
            NodePtr p = node->prev;
            NodePtr n(new Node());
            n->count = count;
            n->values.insert(key);
            p->next = n;
            n->prev = p;
            n->next = node;
            node->prev = n;
            table[key] = n;
          }
        }
      }
    }
  }
/** Decrements an existing key by 1. If Key's value is 1, remove it from the
   * data structure. */
  void dec(string key) {
    if (table.find(key) == table.end()) {
      return;
    }
    auto node = table[key];
    int count = node->count;
    if (node->count == 1) {
      if (node->values.size() == 1) {
        root->prev = node->prev;
        node->prev->next = root;
      } else {
        node->values.erase(key);
      }
      table.erase(key);
    } else {
      if (node->values.size() == 1) {
        if (node->next->count == count - 1) {
          node->next->values.insert(key);
          node->next->prev = node->prev;
          node->prev->next = node->next;
          table[key] = node->next;
        } else {
          node->count = count - 1;
        }
      } else {
        node->values.erase(key);
        if (node->next->count != count - 1) {
          NodePtr p = node->next;
          NodePtr n(new Node());
          n->count = count - 1;
          n->values.insert(key);
          p->prev = n;
          n->prev = node;
          n->next = p;
          table[key] = n;
        } else if (node->next->count == count - 1) {
          node->next->values.insert(key);
          table[key] = node->next;
        } else if (node->next == root) {
          NodePtr n(new Node());
          n->count = count - 1;
          n->values.insert(key);
          node->next = n;
          n->prev = node;
          root->next = n;
          n->next = root;
          table[key] = n;
        }
      }
    }
  }

  /** Returns one of the keys with maximal value. */
  string getMaxKey() {
    return root->next == root ? std::string() : *(root->next->values.begin());
  }

  /** Returns one of the keys with Minimal value. */
  string getMinKey() {
    return root->prev == root ? std::string() : *(root->prev->values.begin());
  }

  std::unordered_map<string, NodePtr> table;
  NodePtr root;

};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end