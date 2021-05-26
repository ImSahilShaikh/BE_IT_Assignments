import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  expense = 0
  income = 0
  saving = this.income- this.expense
  showIncomeForm = false
  showExpenseForm = false
  title = 'payments-app';

  updateSaving() {
    this.saving = this.income - this.expense;
  }
  incomeFormApp(value:any){
    console.log(value);
    this.showIncomeForm = value
    this.showExpenseForm = false
  }

  expenseFormApp(value:any){
    this.showExpenseForm = value
    this.showIncomeForm = false
  }

  updateIncome(value:any) {
    if(isNaN(Number(value.value))){
      alert("The amount should be a number")
      return
    }
    if(Number(value.value) <  0){
      alert("Income cannot be negative")
      return
    }
    this.income = this.income + Number(value.value)
    this.showIncomeForm = false
    this.updateSaving()
  }

  updateExpense(value:any) {
    if(isNaN(Number(value.value))){
      alert("The amount should be a number")
      return
    }
    const a = this.expense + Number(value.value)
    if(Number(value.value) < 0){
      alert("Expense cannot be negative")
      return
    }
    if(a > this.income){
      alert('Expense cannot be more than income')
      return
    }
    this.expense = this.expense + Number(value.value)
    this.showExpenseForm = false
    this.updateSaving()
  }

  clearStats(){
    this.income = 0
    this.expense = 0
    this.updateSaving()
  }
}
