import { Component, EventEmitter, OnInit, Output } from '@angular/core';
import { FormControl } from '@angular/forms';

@Component({
  selector: 'app-income-form',
  templateUrl: './income-form.component.html',
  styleUrls: ['./income-form.component.css']
})
export class IncomeFormComponent implements OnInit {
  @Output() updateIncome = new EventEmitter()

  income = new FormControl('');
  constructor() { }
  onClick() {
    if(this.income) {
      this.updateIncome.emit(this.income)
      this.income.setValue("")
    }
  } 
  ngOnInit(): void {
  }

}
