### 1 - CPP spread operator to extract values from a string of same pattern

vector<string>& logs = ["s1 error","s2 log","s1 error", "s1 error", "s2 log"];

for (const string& log : logs) {
    string serverId, status;
    istringstream iss(log);
    iss >> serverId >> status;
    <!-- serverId = s1, status = error -->
}

istringstream iss(log); : This line creates an input string stream (istringstream) named iss and initializes it with the content of the log string. This allows you to treat the log string as if it were an input stream, making it easier to extract values from it.

iss >> serverId >> status;: This line uses the >> operator to extract values from the input stream iss. It attempts to read two values from iss and store them in the serverId and status variables. The extraction is done based on whitespace separation, so it reads the first word (server ID) into serverId and the second word (success/error) into status.