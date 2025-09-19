class Spreadsheet {
    vector<vector<int>> sheet;
public:
    Spreadsheet(int rows) {
        sheet.resize(rows+1, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        string str = cell.substr(1);
        int row = stoi(str);
        sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        int col = cell[0] - 'A';
        string str = cell.substr(1);
        int row = stoi(str);
        sheet[row][col] = 0;
    }
    
    int getValue(string formula) {
        int row1 = 0, row2 = 0, col1 = 0, col2 = 0, num1 = 0, num2 = 0;
        int i;
        if(formula[1] >= 'A' && formula[1] <= 'Z'){
            i=2;
            col1 = formula[1] - 'A';
            while(formula[i] != '+'){
                row1 = row1 * 10 + (formula[i] - '0');
                i++;
            }
        }
        else{
            i=1;
            while(formula[i] != '+'){
                num1 = num1 * 10 + (formula[i] - '0');
                i++;
            }
        }
        i++;
        if(formula[i] >= 'A' && formula[i] <= 'Z'){
            col2 = formula[i] - 'A';
            i++;
            while(i < formula.size()){
                row2 = row2 * 10 + (formula[i] - '0');
                i++;
            }
        }
        else{
            while(i < formula.size()){
                num2 = num2 * 10 + (formula[i] - '0');
                i++;
            }
        }
        cout<<row1<<" "<<row2<<" "<<col1<<" "<<col2<<" "<<num1<<" "<<num2<<endl;
        return sheet[row1][col1] + sheet[row2][col2] + num1 + num2;    
    }
};
/**/
/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */