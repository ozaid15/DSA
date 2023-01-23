vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> ans;
    if(root == nullptr) return ans;
    deque<Node*> dq;
 
    // Insert the root of the tree into the deque
    dq.push_back(root);
    
    // Create a  variable that will switch in each iteration
    bool reverse = true;
 
    // Start iteration
    while (!dq.empty()) {
 
        // Save the size of the deque here itself, as in
        // further steps the size of deque will frequently
        // change
        int n = dq.size();
 
        // If we are printing left to right
        if (!reverse) {
 
            // Iterate from left to right
            while (n--) {
 
                // Insert the child from the back of the
                // deque Left child first
                if (dq.front()->left != NULL)
                    dq.push_back(dq.front()->left);
 
                if (dq.front()->right != NULL)
                    dq.push_back(dq.front()->right);
 
                // Print the current processed element
                ans.push_back(dq.front()->data);
                dq.pop_front();
            }
            // Switch reverse for next traversal
            reverse = !reverse;
        }
        else {
 
            // If we are printing right to left
            // Iterate the deque in reverse order and insert
            // the children from the front
            while (n--) {
                // Insert the child in the front of the
                // deque Right child first
                if (dq.back()->right != NULL)
                    dq.push_front(dq.back()->right);
 
                if (dq.back()->left != NULL)
                    dq.push_front(dq.back()->left);
 
                // Print the current processed element
                ans.push_back(dq.back()->data);
                dq.pop_back();
            }
            // Switch reverse for next traversal
            reverse = !reverse;
        }
    }
    return ans;
}
