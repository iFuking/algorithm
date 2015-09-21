#include <iostream>

#include <stack>

#include <vector>

#define MAXLEN 110

using namespace std;



typedef struct

{

        char matrix;

        int m_dem;

        int n_dem;

}MATRIX;  // define a struct



int main()

{

        int N;

        cin >> N;

        // save all matrixes in a vector

        vector<MATRIX> v;

        MATRIX mx;

        for (int i = 0; i < N; i++)

        {

                cin >> mx.matrix >> mx.m_dem >> mx.n_dem;

                v.push_back(mx);

        }



        int ans;  // save final answer

        char str[MAXLEN];  // the expression, like (A(BC))

        while (cin >> str)

        {

                ans = 0;

                // save results of each operation

                stack<MATRIX> res;

                for (int i = 0; str[i] != '\0'; i++)

                {

                        if (str[i] == '(') continue;  // ignore '('



                        else if (str[i] == ')' && res.size() > 1)  {

                                  // pop two matrixes if meet ')'

                                MATRIX m1 = res.top(); res.pop();

                                MATRIX m2 = res.top(); res.pop();

                                if (m2.n_dem != m1.m_dem)  // actually, it's matrix m2*m1

                                {

                                        cout << "error" << endl;

                                        break;

                                }

                                ans += m2.m_dem*m2.n_dem*m1.n_dem;

								MATRIX m;

								m.matrix = 'X';
								m.m_dem = m2.m_dem;
								m.n_dem = m1.n_dem;
								res.push(m);



                        } else {  // find & push matrix 

                                vector<MATRIX>::iterator iter = v.begin();

                                for ( ; iter != v.end(); iter++) {

                                        if (str[i] == iter->matrix) { res.push(*iter); break; }

                                }

                        }

                }
				cout << ans << endl;
        }

        return 0;

}

