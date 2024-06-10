  /* USER CODE BEGIN WHILE */
  uint32_t t0,t1;
  t0 = HAL_GetTick();
  while (1)
  {
	  if(t0 < HAL_GetTick())
	  {
		  t0 += 500;
		  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
	  }
	  
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
