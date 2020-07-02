// https://leetcode.com/problems/fruit-into-baskets/

class Solution
{
public:
    int totalFruit(vector<int> &tree)
    {
        unordered_map<int, int> lookup;
        int left = 0, right = 0, res = INT_MIN;

        while (right < tree.size())
        {
            // increase the frequency of the newly added element in the lookup table
            lookup[tree[right]]++;

            // If the current window is invalid
            while (lookup.size() > 2)
            {
                // in case the frequency becomes 0, remove it from the hashmap
                if (--lookup[tree[left]] == 0)
                {
                    lookup.erase(tree[left]);
                }
                // move the left boundary
                left++;
            }

            // Compare number of elements in current window with best till now
            res = max(right - left + 1, res);
            // increment the right boundary of the window

            right++;
        }
        return res;
    }
};

//////////////////////////////////////////////////
///// EQUIVALENT BUT MORE VERBOSE SOLUTION ///////
//////////////////////////////////////////////////

class Solution
{
public:
    int totalFruit(vector<int> &tree)
    {
        unordered_map<int, int> lookup;
        int left = 0, right = 0, res = INT_MIN;

        while (right < tree.size())
        {
            // increase the frequency of the newly added element in the lookup table
            lookup[tree[right]]++;

            // if this is a valid window, check if it's greater than the current best
            if (lookup.size() <= 2)
            {
                res = max(right - left + 1, res);
            }

            // If the current window is invalid
            else
            {
                // Until the window is invalid, keep shrinking the window
                // by moving the left boundary
                while (lookup.size() > 2)
                {
                    // in case the frequency becomes 0, remove it from the hashmap
                    if (--lookup[tree[left]] == 0)
                    {
                        lookup.erase(tree[left]);
                    }
                    // move the left boundary
                    left++;
                }
            }

            // increment the right boundary of the window
            right++;
        }
        return res;
    }
};
