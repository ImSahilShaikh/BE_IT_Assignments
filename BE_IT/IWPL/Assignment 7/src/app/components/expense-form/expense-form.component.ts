import { Component, EventEmitter, OnInit, Output } from '@angular/core';
import { FormControl } from '@angular/forms';

@Component({
  selector: 'app-expense-form',
  templateUrl: './expense-form.component.html',
  styleUrls: ['./expense-form.component.css']
})
export class ExpenseFormComponent implements OnInit {
  @Output() updateExpense = new EventEmitter()

  expense = new FormControl('');
  constructor() { }
  onClick() {
    if(this.expense) {
      this.updateExpense.emit(this.expense)
      this.expense.setValue("")
    }
  } 
  ngOnInit(): void {
  }

}
