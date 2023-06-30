// Time Complexity - O(N) + O(NlogN)
// Space Complexity - O(N)

#include <bits/stdc++.h>
using namespace std;
// Create a structure named “meet”, with three entities,
// namely: meeting number, start time and end time.
struct meet
{
    int meetingID;
    int startTime;
    int endTime;
};

bool compare(struct meet a, struct meet b)
{
    if (a.endTime == b.endTime)
    {
        return a.meetingID < b.meetingID;
    }
    else
    {
        return a.endTime < b.endTime;
    }
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();

    // Create the struct array MEETING of size N and
    struct meet meeting[n];

    // initialize it with the given start, end times, and 1-based indexes.
    for (int i = 0; i < n; i++)
    {
        meeting[i].meetingID = i + 1;
        meeting[i].startTime = start[i];
        meeting[i].endTime = end[i];
    }

    // Maintain a vector “result” to store the meeting number of the
    // meetings scheduled in one room.
    vector<int> result;

    // Declare a variable “prev_end” to store the
    // ending time of the previous meeting selected.
    int prevEnd;

    // Sort the array MEETING in increasing order of the end times.
    sort(meeting, meeting + n, compare);

    // The first meeting of the MEETING array is selected,
    // and its meeting number of pushed in the result vector.
    //  Update the prev_end as MEETING[0].end
    result.push_back(meeting[0].meetingID);
    prevEnd = meeting[0].endTime;

    // Traverse the entire MEETING array and keep selecting
    // the meetings whose start time is strictly greater than prev_end.
    for (int i = 1; i < n; i++)
    {
        // If startTime of current meeting is greater than our currentTime.
        // Then we will perform this meeting and update currentTime with endTime of
        // the meeting.
        if (meeting[i].startTime > prevEnd)
        {
            result.push_back(meeting[i].meetingID);
            prevEnd = meeting[i].endTime;
        }
    }

    // Return the result vector.
    return result;
}