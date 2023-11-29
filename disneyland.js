// Define a DisneylandTicket class

class DisneylandTicket {
  constructor(name, age, type, price, days) {
    this.name = name;
    this.age = age;
    this.type = type;
    this.price = price;
    this.days = days || 1; // Default to 1 day if not specified
  }

  calculateTotalCost() {
    const discountedPrice = calculateDiscountedPrice(this.age, this.price);
    return discountedPrice * this.days;
  }

  displayTicketInfo() {
    const discountedPrice = calculateDiscountedPrice(this.age, this.price);
    const purchaseDateValid = isValidPurchaseDate();
    console.log(`Ticket Information:
        Name: ${this.name}
        Age: ${this.age}
        Type: ${this.type}
        Original Price: $${this.price.toFixed(2)}
        Discounted Price: $${discountedPrice.toFixed(2)}
        Purchase Date Valid: ${purchaseDateValid ? 'Yes' : 'No'}
        Number of Days: ${this.days}
      `);
  }
}



// Function to calculate the total cost of an array of tickets

function calculateTotalCost(tickets) {
  let totalCost = 0;

  tickets.forEach(ticket => {
    totalCost += ticket.calculateTotalCost();
  });

  return totalCost;
}


// Function to check if a visitor is eligible for a senior discount

function isSenior(visitorAge) {
  return visitorAge >= 65;
}


// Function to check if a visitor is eligible for a child discount

function isChild(visitorAge) {
  return visitorAge <= 12;
}


// Function to validate the purchase date of a ticket

function isValidPurchaseDate() {
  const currentDate = new Date();

  // Assuming Disneyland is open year-round for simplicity
  // You can add more complex logic for specific opening and closing dates

  return true;
}


// Function to calculate the discounted price based on age

function calculateDiscountedPrice(age, originalPrice) {
  const seniorDiscount = isSenior(age) ? 0.2 : 0; // 20% senior discount if eligible
  const childDiscount = isChild(age) ? 0.1 : 0; // 10% child discount if eligible
  return originalPrice * (1 - seniorDiscount - childDiscount);
}


// Example usage with updated ticket information, discounts, date validation, and number of days

const ticketsArray = [
  new DisneylandTicket('Diamant Serrani', 25, 'Adult', 89.99, 2),
  new DisneylandTicket('Roberta Serrani', 70, 'Senior', 49.99, 1),
  new DisneylandTicket('Laura Serrani', 8, 'Child', 59.99, 3),
];


// Display individual updated ticket information

ticketsArray.forEach(ticket => {
  ticket.displayTicketInfo();
});


// Calculate and display total cost with discounts, date validation, and number of days

const totalCostWithDiscountsValidationDays = calculateTotalCost(ticketsArray);

console.log(`Total Cost with Discounts, Date Validation, and Number of Days for the group: $${totalCostWithDiscountsValidationDays.toFixed(2)}`);
