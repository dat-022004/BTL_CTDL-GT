#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

// Hàm xóa màn hình
void clearScreen() {
    // Dùng "cls" cho Windows, "clear" cho Linux/Mac
    system("cls");  // Dùng "clear" nếu bạn đang sử dụng Linux/Mac
}

// DFS - Duyet do thi theo chieu sau
void DFS(int u, vector<bool>& visited, vector<vector<int>>& adj) {
    stack<int> s;
    s.push(u);
    visited[u] = true;

    while (!s.empty()) {
        int v = s.top();
        s.pop();
        cout << v << " ";  // In ra dinh da tham

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                s.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

// BFS - Duyet do thi theo chieu rong
void BFS(int start, vector<bool>& visited, vector<vector<int>>& adj) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";  // In ra dinh da tham

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

// Dijkstra - Tim duong di ngan nhat tu dinh nguon
void Dijkstra(int start, vector<vector<pair<int, int>>>& adj, int n) {
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Khoang cach ngan nhat tu dinh " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "Khong co duong di den dinh " << i << endl;
        } else {
            cout << "Khoang cach den dinh " << i << ": " << dist[i] << endl;
        }
    }
}

// Bellman-Ford - Tim duong di ngan nhat cho do thi co trong so am
void BellmanFord(int n, vector<pair<int, pair<int, int>>>& edges, int start) {
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (auto& edge : edges) {
            int u = edge.first;
            int v = edge.second.first;
            int weight = edge.second.second;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second.first;
        int weight = edge.second.second;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Do thi chua vong lap co trong so am!\n";
            return;
        }
    }

    cout << "Khoang cach ngan nhat tu dinh " << start << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INT_MAX) {
            cout << "Khong co duong di den dinh " << i << endl;
        } else {
            cout << "Khoang cach den dinh " << i << ": " << dist[i] << endl;
        }
    }
}

// Floyd-Warshall - Tim tat ca cac duong di ngan nhat giua moi cap dinh
void FloydWarshall(int n, vector<vector<int>>& dist) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Khoang cach ngan nhat giua moi cap dinh:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n, m, choice;

    cout << "Nhap so luong dinh: ";
    cin >> n;
    cout << "Nhap so luong canh: ";
    cin >> m;

    // Khoi tao do thi
    vector<vector<int>> adjList(n);  // Do thi cho DFS va BFS
    vector<vector<pair<int, int>>> adj(n);  // Do thi co trong so cho Dijkstra
    vector<pair<int, pair<int, int>>> edges;  // Canh cho Bellman-Ford

    // Nhap cac canh cho DFS, BFS, Dijkstra va Bellman-Ford
    cout << "Nhap cac canh (u, v, weight):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cout << "Canh " << i + 1 << ": ";
        cin >> u >> v >> weight;

        // Kiểm tra xem các chỉ số u, v có hợp lệ không
        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Chi so dinh khong hop le. Vui long nhap lai.\n";
            i--;  // Yêu cầu nhập lại canh hiện tại
            continue;
        }

        adjList[u].push_back(v);
        adjList[v].push_back(u);
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
        edges.push_back({u, {v, weight}});
    }

    do {
        cout << "\n===== MENU =====";
        cout << "\n1. Thuc hien DFS";
        cout << "\n2. Thuc hien BFS";
        cout << "\n3. Thuc hien Dijkstra";
        cout << "\n4. Thuc hien Bellman-Ford";
        cout << "\n5. Thuc hien Floyd-Warshall";
        cout << "\n6. Thoat";
        cout << "\nNhap lua chon cua ban: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int start;
                cout << "Nhap dinh bat dau cho DFS: ";
                cin >> start;
                if (start < 0 || start >= n) {
                    cout << "Dinh bat dau khong hop le.\n";
                    break;
                }
                vector<bool> visited(n, false);
                cout << "DFS: ";
                DFS(start, visited, adjList);
                cout << endl;
                break;
                clearScreen();
            }

            case 2: {
                int start;
                cout << "Nhap dinh bat dau cho BFS: ";
                cin >> start;
                if (start < 0 || start >= n) {
                    cout << "Dinh bat dau khong hop le.\n";
                    break;
                }
                vector<bool> visited(n, false);
                cout << "BFS: ";
                BFS(start, visited, adjList);
                cout << endl;
                break;
                  clearScreen();
            }

            case 3: {
                int start;
                cout << "Nhap dinh bat dau cho Dijkstra: ";
                cin >> start;
                if (start < 0 || start >= n) {
                    cout << "Dinh bat dau khong hop le.\n";
                    break;
                }
                Dijkstra(start, adj, n);
                break;
                  clearScreen();
            }

            case 4: {
                int start;
                cout << "Nhap dinh bat dau cho Bellman-Ford: ";
                cin >> start;
                if (start < 0 || start >= n) {
                    cout << "Dinh bat dau khong hop le.\n";
                    break;
                }
                BellmanFord(n, edges, start);
                break;
                  clearScreen();
            }

            case 5: {
                vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
                for (int i = 0; i < n; ++i) {
                    dist[i][i] = 0;
                }
                cout << "Nhap cac canh cho Floyd-Warshall:\n";
                for (int i = 0; i < m; ++i) {
                    int u, v, weight;
                    cout << "Canh " << i + 1 << ": ";
                    cin >> u >> v >> weight;
                    dist[u][v] = weight;
                    dist[v][u] = weight;  
                }
                FloydWarshall(n, dist);
                break;
                  clearScreen();
            }

            case 6:
                cout << "Thoat chuong trinh.\n";
                break;

            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
        }
 cout << "\nNhan Enter de tiep tuc...";
            cin.ignore();
            cin.get();
    } while (choice != 6);

    return 0;
}
