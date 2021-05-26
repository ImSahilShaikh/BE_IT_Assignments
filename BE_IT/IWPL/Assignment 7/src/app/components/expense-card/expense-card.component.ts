import { Component, OnInit, Input, Output, EventEmitter } from '@angular/core';

@Component({
  selector: 'app-expense-card',
  templateUrl: './expense-card.component.html',
  styleUrls: ['./expense-card.component.css']
})
export class ExpenseCardComponent implements OnInit {
  @Input() expense:any
  @Input() income:any
  @Input() saving:any
  @Output() clear = new EventEmitter();
  showExpense = false
  showIncome = false
  constructor() { }

  ngOnInit(): void {
  }

}
