/* USER CODE BEGIN 0 */
void buzzer (uint8_t state)
{
  if(state==1)  htim2.Instance->CCR3=10;
  else          htim2.Instance->CCR3=0;
}


  /* USER CODE BEGIN 2 */
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);


  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(t0 < HAL_GetTick())
	  {
		  t0 += 10;
      uint8_t pb = HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13);
      sprintf(tx2buf,"\r\nPB status: %d",pb);
      HAL_UART_Transmit_IT(&huart2, (uint8_t*)tx2buf, strlen(tx2buf));

      if(pb==0) buzzer(1);
      if(pb==1) buzzer(0);
	  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
