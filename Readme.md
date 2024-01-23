# Flowchart Designer and Simulator

## Overview

This project is a C++ implementation of a Flowchart Designer and Simulator using the CMUgraphicsLib for graphics rendering. The application allows users to create, visualize, and simulate flowcharts, which are diagrammatic representations of algorithms or processes. Flowcharts are widely used in various fields for analyzing, designing, documenting, and managing processes within a program.

## Features

- **User-Friendly Interface**: The application provides an intuitive and user-friendly interface for designing flowcharts.
  
- **Box Types**: Supports various types of boxes commonly used in flowcharts, including processing steps (rectangular boxes), decisions (diamonds), and inputs/outputs (parallelograms).

- **Connectors**: Enables users to connect different boxes with arrows, representing the flow of the process.

- **Execution Simulation**: Allows users to simulate the execution of the flowchart, providing a step-by-step solution to the given problem.

- **Conversion to C++ Code**: Provides an additional feature to convert the designed flowchart into a C++ code file.

## Requirements

- **C++ Compiler**: Ensure that you have a C++ compiler installed to build and run the application.

- **CMUgraphicsLib**: The project uses CMUgraphicsLib for graphics rendering. Make sure to include the library in your project.

## Getting Started

1. **Clone the Repository**: Clone this repository to your local machine.

   ```bash
   git clone https://github.com/your-username/flowchart-designer.git
   ```

2. **Build the Project**: Use your preferred C++ compiler to build the project. Ensure that you link the CMUgraphicsLib library.

   ```bash
   g++ -o flowchart_simulator flowchart_simulator.cpp -lcmu_graphics
   ```

3. **Run the Application**: Execute the compiled application.

   ```bash
   ./flowchart_simulator
   ```

## Usage

1. **Design Flowchart**: Use the application interface to design your flowchart by adding boxes, connectors, and defining the logic.

2. **Simulate Execution**: Simulate the execution of the flowchart to visualize the step-by-step solution.

3. **Conversion to C++ Code**: If desired, use the bonus feature to convert the designed flowchart into a C++ code file.

## Contributing

Feel free to contribute to the development of this project by submitting pull requests or reporting issues. Your feedback and contributions are highly appreciated.
