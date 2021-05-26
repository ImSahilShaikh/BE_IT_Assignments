import { Component, Input, OnInit, Output, EventEmitter } from '@angular/core';

@Component({
  selector: 'app-header',
  templateUrl: './header.component.html',
  styleUrls: ['./header.component.css']
})
export class HeaderComponent implements OnInit {
  @Input() showIncomeForm:any
  @Input() showExpenseForm:any
  @Output() incomeForm = new EventEmitter();
  @Output() expenseForm = new EventEmitter();
  constructor() { }
  ngOnInit(): void {
  }

}
