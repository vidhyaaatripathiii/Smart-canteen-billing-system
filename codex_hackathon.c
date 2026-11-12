
#include <stdio.h>

int main()
{
    // Storing food item prices
    int price[8] = {80, 120, 60, 100, 40, 50, 30, 70};

    // Storing food item names
    char *items[8] = {
        "Burger",
        "Pizza",
        "Sandwich",
        "Pasta",
        "French Fries",
        "Cold Coffee",
        "Tea",
        "Momos"
    };

    int choice, quantity;
    int qty[8];
    int i, again;

    float subtotal, discount, finalAmount;

    do
    {
        // Reset quantities whenever a new bill starts
        for(i = 0; i < 8; i++)
        {
            qty[i] = 0;
        }

        subtotal = 0;
        discount = 0;

        // Displaying the canteen menu
        printf("\n========================================\n");
        printf("       CODEX - SMART CANTEEN\n");
        printf("========================================\n");

        printf("\n--------------- FOOD MENU --------------\n");

        printf("1. Burger          - Rs. 80\n");
        printf("2. Pizza           - Rs. 120\n");
        printf("3. Sandwich        - Rs. 60\n");
        printf("4. Pasta           - Rs. 100\n");
        printf("5. French Fries    - Rs. 40\n");
        printf("6. Cold Coffee     - Rs. 50\n");
        printf("7. Tea             - Rs. 30\n");
        printf("8. Momos           - Rs. 70\n");
        printf("9. Generate Bill\n");

        printf("----------------------------------------\n");

        // Taking multiple food selections
        while(1)
        {
            printf("\nEnter your choice (1-9): ");
            scanf("%d", &choice);

            // Exit the ordering loop to generate the bill
            if(choice == 9)
            {
                break;
            }

            // Checking whether the menu choice is valid
            if(choice < 1 || choice > 8)
            {
                printf("Invalid choice! Please try again.\n");
                continue;
            }

            // Taking quantity of the selected food item
            printf("Enter quantity of %s: ", items[choice - 1]);
            scanf("%d", &quantity);

            // Checking whether the quantity is valid
            if(quantity <= 0)
            {
                printf("Invalid quantity! Enter a positive number.\n");
                continue;
            }

            // Adding quantity to the selected food item
            qty[choice - 1] += quantity;

            printf("%s added successfully!\n", items[choice - 1]);
        }

        // Calculating the subtotal
        for(i = 0; i < 8; i++)
        {
            subtotal = subtotal + (qty[i] * price[i]);
        }

        // Applying 10% discount if subtotal exceeds Rs. 500
        if(subtotal > 500)
        {
            discount = subtotal * 0.10;
        }

        // Calculating final payable amount
        finalAmount = subtotal - discount;

        // Displaying the final bill
        printf("\n\n========================================\n");
        printf("              CODEX BILL\n");
        printf("========================================\n");

        printf("%-18s %-8s %-10s\n", "Item", "Qty", "Amount");
        printf("----------------------------------------\n");

        // Displaying only the items selected by the customer
        for(i = 0; i < 8; i++)
        {
            if(qty[i] > 0)
            {
                printf("%-18s %-8d Rs. %-7d\n",
                       items[i],
                       qty[i],
                       qty[i] * price[i]);
            }
        }

        printf("----------------------------------------\n");

        printf("Subtotal          : Rs. %.2f\n", subtotal);
        printf("Discount (10%%)    : Rs. %.2f\n", discount);

        printf("----------------------------------------\n");

        printf("FINAL AMOUNT      : Rs. %.2f\n", finalAmount);

        printf("========================================\n");
        printf("          THANK YOU! VISIT AGAIN\n");
        printf("========================================\n");

        // Asking whether the customer wants another bill
        printf("\nDo you want to generate another bill?\n");
        printf("1. Yes\n");
        printf("2. No\n");

        printf("Enter your choice: ");
        scanf("%d", &again);

        // Checking whether the repeat choice is valid
        while(again != 1 && again != 2)
        {
            printf("Invalid choice! Enter 1 or 2: ");
            scanf("%d", &again);
        }

    } while(again == 1);

    printf("\nThank you for using CODEX!\n");

    return 0;
}
