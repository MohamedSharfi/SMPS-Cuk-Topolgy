# SMPS - Cuk's Topology

This project is an assignment given by my lecturer, where I am tasked with designing and simulating a Buck-Boost converter. After some research, I chose Cuk topology, one of the more modern and efficient converter designs, for this project. 

## Project Overview

The project consists of the following stages:

1. **Design**
   - Determine the passive component values.
   - Reference research papers to support the calculations (documentation will be provided soon).

2. **Simulation**
   - Use MATLAB to calculate the efficiency of the converter.
   - Note: The simulation results may not be fully accurate due to the exclusion of switching losses.

3. **PCB Development**
   - **Objective**: Upscale the project by designing and fabricating a PCB.
   - **Approach**:
     - Develop two PCB prototypes:
       1. Using **JLCPCB** for a professional-grade prototype.
       2. Manually manufacture a PCB in the university lab to gain hands-on experience in the PCB fabrication process.
   - Collaborate with my lecturer to ensure the project progresses in the right direction and minimizes material wastage.

4. **Inductor Design**
   - Post-PCB fabrication, calculate the new inductor value.
   - Design the inductor in-house using lab facilities, referencing the *Transformer and Inductor Design Handbook* by Colonel Wm. T. McLyman, specifically Chapter 8 on DC inductors with gapped cores.
   - Key considerations:
     - Wire width
     - Winding area
     - Number of windings
     - Other critical parameters

5. **Final Adjustments**
   - If the calculated inductor value is unwoundable:
     - Adjust system specifications.
     - The most viable solution is to increase the switching frequency, as other changes may affect the rated power.

## Goals

- Enhance understanding of Cuk topology and its practical implementation.
- Gain hands-on experience in PCB design and fabrication.
- Learn inductor design and optimization for real-world applications.

## Tools & Resources

- **Software**: MATLAB
- **PCB Fabrication**: JLCPCB and University PCB Lab
- **Reference Material**: *Transformer and Inductor Design Handbook* by Colonel Wm. T. McLyman

## Future Updates

- Research papers and detailed documentation will be added soon.
- Updates on the PCB manufacturing process and test results will be shared.

---

### Contributions

This project is conducted under the guidance of my lecturer, who provides valuable insights to ensure efficient use of time and resources.

---
