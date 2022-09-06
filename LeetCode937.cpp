#include <iostream>
#include <string>
#include <vector>

using namespace std;

/// <summary>
/// 937. Reorder Data in Log Files
/// </summary>

struct LetterLogs
{
    string data;
    int startPoint;
};

class Solution {
private:
    int compIndex(LetterLogs l1, LetterLogs l2) {
        int len1 = l1.startPoint;
        int len2 = l2.startPoint;

        int n;
        if (len1 > len2) n = len1;
        else n = len2;

        for (int i = 0; i < n; i++) {
            if (l1.data[i] < l2.data[i]) return -1;
            if (l1.data[i] > l2.data[i]) return 1;
        }
        if (len1 == len2) return 0;
        if (len1 > len2) return 1;
        else return -1;
    }

    int comp(LetterLogs l1, LetterLogs l2) {
        int len1 = l1.data.length() - l1.startPoint;
        int len2 = l2.data.length() - l2.startPoint;

        int n;
        if (len1 > len2) n = len1;
        else n = len2;

        for (int i = 0; i < n; i++) {
            if (l1.data[l1.startPoint + i] < l2.data[l2.startPoint + i]) return -1;
            if (l1.data[l1.startPoint + i] > l2.data[l2.startPoint + i]) return 1;
        }
        if (len1 == len2) return compIndex(l1, l2);
        if (len1 > len2) return 1;
        else return -1;
    }
    void sortData(vector<LetterLogs>& logs) {
        int len = logs.size();
        mergeSort(logs, 0, len - 1);
    }
    void mergeSort(vector<LetterLogs>& log, int start, int end) {
        if (start >= end) return;
        int mid = start + (end - start) / 2;
        mergeSort(log, start, mid);
        mergeSort(log, mid + 1, end);
        merge(log, start, mid, end);
    }
    void merge(vector<LetterLogs>& log, int left, int mid, int right) {
        int one = mid - left + 1;
        int two = right - mid;

        LetterLogs* leftA = new LetterLogs[one];
        LetterLogs* rightA = new LetterLogs[two];

        for (int i = 0; i < one; i++) {
            leftA[i] = log[left + i];
        }

        for (int j = 0; j < two; j++) {
            rightA[j] = log[mid + 1 + j];
        }

        int iSAO = 0;
        int iSAT = 0;
        int iMA = left;

        while (iSAO < one && iSAT < two) {
            int res = comp(leftA[iSAO], rightA[iSAT]);
            //cout << "l1 :: " << leftA[iSAO].data << " :: l2 :: " << rightA[iSAT].data << " :: " << res << endl;
            if (res <= 0) {
                log[iMA] = leftA[iSAO];
                iSAO++;
            }
            else {
                log[iMA] = rightA[iSAT];
                iSAT++;
            }
            iMA++;
        }

        while (iSAO < one) {
            log[iMA] = leftA[iSAO];
            iSAO++;
            iMA++;
        }

        while (iSAT < two) {
            log[iMA] = rightA[iSAT];
            iSAT++;
            iMA++;
        }
    }
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> dLogs;
        vector<LetterLogs> lData;
        for (int i = 0; i < logs.size(); i++) {
            string s = logs[i];
            int prevAsc = -1;
            for (int j = 0; j < s.length(); j++) {
                char c = s[j];
                int asc = (int)c;
                if (prevAsc == 32) {
                    if (asc > 47 && asc < 58) dLogs.push_back(s);
                    else {
                        LetterLogs ll;
                        ll.data = s;
                        ll.startPoint = j;
                        lData.push_back(ll);
                    }
                    break;
                }
                prevAsc = asc;
            }
        }
        //cout << " Digits :: " << dLogs.size() << endl;
        //cout << " Letters :: " << lData.size() << endl;
        sortData(lData);
        vector<string> result;
        for (int i = 0; i < lData.size(); i++) {
            result.push_back(lData[i].data);
        }
        for (int i = 0; i < dLogs.size(); i++) {
            result.push_back(dLogs[i]);
        }
        return result;
    }
};