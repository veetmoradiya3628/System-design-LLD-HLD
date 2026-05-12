- LLD
    - LLD is a process of translating high-level components into working code structure. It bridges the gap between architecture and implementation.
    - It defines the classes, interfaces, methods, and their relationships that implement a specific functionality.
    - Example
        - HLD says "We need a notification service"
        - LLD says "We'll use an interface NotificationSender with concrete classes like EmailSender, SmsSender and PushNotificationSender, all managed by a NotificationManager"
    - flow
        ```
        Requirements --> HLD --> LLD --> Code Implementation
        ``` 
    - LLD is not about writing code that works, its about writing code that's modular, testable, extensible and easy to reason about as the system grows.
- Core components of LLD
    1. Classes and Objects
        - Identify main entities & their roles
        - questions
            1. what are the key classes ?
            2. what are their responsibilities ?
            3. what data do they holds (attributes) ?
            4. what operations do they perform (methods) ?
    2. Interfaces and Abstractions
        - Interfaces define contracts between components. They are critical to ensure loose coupling, allowing multiple components to interact without depending on each other's internal implementation details.
        - Ask yourself
            1. What functionality should a class expose to the outside world ?
            2. What details should remain hidden ?
            3. Which parts of the system are likely to change or have multiple variations ?
    3. Relationships Between Classes
        - Classes don't exist in isolation. LLD defines these relationships clearly and precisely.
        - Key Relationships
            1. Association
                - A general uses-a relationship
            2. Aggregation (Weak "has-a")
                - An object contains other objects, but they can exist independently. A Department has Professors. If the department is closed, the professors still exist.
            3. Composition (Strong "has-a")
                - An object is composed of other objects, and their lifecycles are tied. A House is composed of Rooms. If you demolish the house, the rooms are destroyed with it.
            4. Inheritance ("is-a")
                - A class inherits properties and behaviors from a parent. A Car is a Vehicle.
        - Cardinality
            - One-to-one
            - One-to-many
            - Many-to-many
    4. Method signatures
        - Once your classes and relationships are defined, the next step is deciding how they behave using methods. A well-designed method signature is self-documenting and intuitive.
        - Consistency, readability, and clarity in method signatures make your code intuitive and easier to maintain.
    5. Design patterns
        - LLD is also the stage where you apply proven solutions to common design problems using design patterns. These patterns provide reusable templates that bring structure, robustness, and maintainability to your code.
        - Common LLD patterns 
            1. Singleton
            2. Factory
            3. Strategy
            4. Observer
            5. Decorator
            6. Adapter
            7. Facade
    - Importance of LLD in Software Development
        - Maintainability
        - Scalability & Performance
        - Testability
        - Collaboration
        - Reusability
    - Importance of LLD interviews
        - Problem-solving
        - Object-oriented principles
        - Design principles
        - Design patterns
        - Clean code
        - Communication & trade-offs

- LLD vs. HLD
    - In software engineering, building a complex system is like constructing a city.
    - You wouldn't start by laying bricks for a single house without a city plan. You first need to decide where the residential areas, commercial zones, power grids, and roads will go.
    - This city plan is your High-Level Design (HLD).
    - Once the city plan is approved, an architect takes a single plot of land in a residential zone and designs the detailed blueprint for a house specifying the number of rooms, the plumbing, the electrical wiring, and the materials to be used.
    - This detailed house blueprint is your Low-Level Design (LLD).
    - Both are essential, but they operate at different levels of abstraction and serve different purposes.
    - In this chapter, we will take a deeper look at their differences.
    - What is High-Level Design (HLD)?
        - High-Level Design (HLD) defines the architecture of the system.
        - It answers the question:
        - “How should the system be structured, and how will its major components interact?”
        - The focus here is on the what, not the how.
        - It answers questions like:
            - What are the major components or microservices? (e.g., User Service, Payment Service, Notification Service, Product Catalog)
            - How will these components communicate? (e.g., via REST APIs, gRPC, or a message queue like RabbitMQ or Kafka)
            - What technology stack will be used? (e.g., Java vs. Python, SQL vs. NoSQL database)
            - How will the system handle scalability, reliability, and availability? (e.g., using load balancers, database replication, CDNs)
            - What are the third-party integrations? (e.g., Stripe for payments, AWS S3 for storage)
        - The output of HLD is a set of architectural diagrams, data flow diagrams, and technology choices that define the system's skeleton.
        - Example
            - HLD of a Ride-Hailing App
            - Services: Passenger Service, Driver Service, Matching Service, Billing Service
            - Communication: Matching Service uses a message queue to broadcast ride requests. Passenger and Driver services communicate via WebSockets for real-time location updates.
            - Database: A NoSQL database for location data and a relational SQL database for user and billing information.
            - Infrastructure: Load balancers to distribute traffic, with services deployed as containers on Kubernetes for scalability.
    - What is Low-Level Design (LLD)?
        - LLD zooms in on a single component or module and translates the abstract architectural concepts into concrete, implementable details that developers can code directly.
        - It’s where you decide the internal structure of a service — the classes, methods, data models, design patterns, and relationships.
        - For a single module, it answers questions like:
            - What are the specific classes, and what are their responsibilities?
            - What are the attributes and methods of each class?
            - How do these classes relate to each other (inheritance, composition)?
            - What design patterns are most suitable (e.g., Factory, Singleton, Strategy)?
            - What are the specific method signatures, including parameters, return types, and exceptions?
        - Example
            - LLD of the Billing Service from the Ride-Hailing App
            - Classes: Ride, Invoice, PaymentStrategy, CreditCardPayment, WalletPayment
            - Interfaces: An interface IPaymentStrategy with a method processPayment(amount). CreditCardPayment and WalletPayment would implement this interface.
            - Relationships: The Invoice class "has-a" Ride object (Composition).
            - Design Pattern: The Strategy Pattern is used to allow the user to switch between different payment methods seamlessly.
    - Key Differences: HLD vs. LLD at a Glance
        - Focus
            - HLD: What components exist
            - LLD: How each component is built
        - Audience
            - HLD: Architects, stakeholders
            - LLD: Engineers, developers
        - Abstraction
            - HLD: System-level
            - LLD: Module/class-level
        - Artifacts
            - HLD: System architecture diagrams, tech stack choices
            - LLD: Class diagrams, interaction diagrams, method definitions
        - Example
            - HLD: "We’ll use a microservices architecture with services for users, orders, and payments"
            - LLD: "The OrderService will use a PaymentProcessor interface with two implementations:"
                - StripeProcessor
                - RazorpayProcessor
    - How HLD and LLD Work Together
        - HLD and LLD are not alternatives. They're sequential steps in the design process.
        - Flow
            - Requirements define what the system should do
            - HLD breaks the system into components
            - LLD designs each component's internals
            - Code implements the LLD

- Types of LLD Interviews
    - Companies evaluate LLD skills in very different ways. What works for a whiteboard OOD round at Amazon won't help you in a machine coding round at Flipkart or a concurrency round at Uber.
    - Here are the five common formats of LLD interviews you should be aware of:
    - Overview
        - Object-Oriented Design: Class diagrams, Design discussion, Whiteboard/verbal
        - Machine Coding: Working code, Time pressure, IDE/editor
        - Concurrency Design: Thread safety, Synchronization, Race conditions
        - API Design: Interface design, REST principles, Contracts
        - Schema Design: Database tables, Relationships, Indexing
    - Each format tests different skills and requires different preparation.
    - In this course, we will primarily focus on Object Oriented Design and Machine Coding. There is a separate course dedicated to Concurrency Interview.
    - API Design and Schema Design are typically covered as part of High-Level System Design Interview.
    - 1. Object-Oriented Design (OOD)
        - This is the most common type of LLD interview at major tech companies like Google, Amazon, Meta, and Microsoft.
        - In an OOD interview, you design a system by identifying classes, their attributes, methods, and relationships. The focus is on your design thinking rather than working code.
        - Format
            - Duration: 45-60 minutes
            - Tools: Whiteboard, Google Docs, or virtual whiteboard
            - Code: Usually pseudocode or skeleton classes (not runnable)
            - Deliverable: Class diagrams, interface definitions, key method signatures
            - Interaction: High, lots of back-and-forth with interviewer
        - What Interviewers Evaluate
            - OOP Fundamentals (High): Proper use of inheritance, encapsulation, polymorphism
            - Design Patterns (High): Recognizing when patterns fit naturally
            - SOLID Principles (High): Single responsibility, open/closed, etc.
            - Communication (High): Explaining decisions, responding to feedback
            - Trade-off Discussion (Medium): Justifying choices, considering alternatives
    - 2. Machine Coding
        - Machine coding interviews require you to write working, runnable code within a strict time limit. This format is especially popular at Indian tech companies and startups.
        - You're given a problem and must implement a working solution from scratch. The code must compile, run, and produce correct output. No pseudocode, no hand-waving.
        - Format
            - Duration: 60-90 minutes (sometimes 2 hours)
            - Tools: Your own IDE or online coding platform
            - Deliverable: Working code that compiles and runs
            - Evaluation: Code is reviewed after submission
            - Interaction: Low, usually you work independently
        - What Interviewers Evaluate
            - Coding Speed (High): Can you implement under time pressure?
            - Code Quality (High): Can you write clean, readable, maintainable code?
            - Correctness (High): Does your code work for given test cases?
            - Testing (High): Writing test cases or driver code
            - Project Structure (Medium): Using proper packages, separation of concerns
            - Edge Cases (Medium): Handling invalid inputs gracefully
        - Tips to Succeed
            - Practice typing speed. Seriously. You need to write fast.
            - Know your IDE shortcuts. Every second counts.
            - Start with core functionality. Get basics working first, add features later.
            - Handle input/output early. Parse input format in the first 10 minutes.
            - Test as you go. Don't wait until the end to test.
    - 3. Concurrency Design
        - Concurrency interviews test your ability to design and implement thread-safe systems. These are common at companies building high-performance or distributed systems.
        - You're asked to design a system that handles concurrent access correctly. This might involve implementing thread-safe data structures, handling race conditions, or designing synchronization strategies.
        - Format
            - Duration: 60-90 minutes
            - Tools: Whiteboard + code (often Java or C++)
            - Deliverable: Thread-safe design with synchronization strategy
            - Focus: Race conditions, deadlocks, performance
        - What Interviewers Evaluate
            - Race Condition Identification (High): Can you spot where race conditions occur?
            - Synchronization Primitives (High): Correct use of locks, semaphores, etc.
            - Deadlock Prevention (High): Understanding and preventing deadlocks
            - Performance Awareness (Medium): Lock granularity, contention
            - Correctness Reasoning (High): Can you prove your solution is correct?
        - Tips to Succeed
            - Know the primitives. Understand when to use each synchronization tool.
            - Identify shared state first. What data is accessed by multiple threads?
            - Think about access patterns. Read-heavy vs write-heavy affects your choice.
            - Prevent deadlocks. Know the deadlock conditions and how to avoid them.
            - Consider performance. Fine-grained locks vs coarse-grained locks.
    - 4. API Design
        - API design interviews focus on designing clean, usable interfaces. This tests your ability to create abstractions that other developers will use.
        - You design the public interface of a library, service, or module. The focus is on method signatures, contracts, and usability, not internal implementation.
        - Format
            - Duration: 30-45 minutes
            - Tools: Whiteboard or document
            - Deliverable: API signatures, request/response formats, error handling
            - Interaction: High, discussion about design choices
        - What Interviewers Evaluate
            - Usability (High): Is the API easy to use correctly?
            - Consistency (High): Naming conventions, parameter patterns
            - Extensibility (Medium): Can it evolve without breaking changes?
            - Error Handling (Medium): Meaningful error codes and messages
            - REST Principles (Medium): Proper resource modeling for web APIs
        - Tips to Succeed
            - Study good APIs. Learn from Stripe, Twilio, GitHub APIs.
            - Follow REST conventions. Proper resource naming, HTTP methods.
            - Think about pagination. How will users handle large result sets?
            - Plan for errors. Clear error codes and messages.
            - Consider versioning. How will you evolve the API?
            - Think about authentication. API keys, OAuth, JWT.
    - 5. Schema Design
        - Schema design interviews test your ability to model data in a database. This is often combined with OOD or asked as part of high-level design (HLD) round.
        - You design database tables, define relationships, and consider indexing and query patterns. The focus is on data modeling, not application logic.
        - Format
            - Duration: 30-45 minutes (often part of a larger round)
            - Tools: Whiteboard or ER diagram tool
            - Deliverable: Tables, columns, relationships, indexes, maybe some SQL
            - Focus: Normalization, query efficiency, data integrity
        - What Interviewers Evaluate
            - Data Modeling (High): Identifying entities and relationships
            - Normalization (High): Proper level of normalization (1NF, 2NF, 3NF)
            - Constraints (High): Primary keys, foreign keys, unique constraints
            - Indexing (Medium): Appropriate indexes for queries
            - Query Patterns (Medium): Design supports expected queries
        - Tips to Succeed
            - Know normalization. Understand 1NF, 2NF, 3NF and when to apply.
            - Think about queries. Design should support the queries you'll run.
            - Choose indexes wisely. Too many is as bad as too few. Design indexes based on query patterns.
            - Consider scale. How will the schema perform at 10x data? Consider sharding / partitioning.
            - Handle edge cases. Soft deletes, audit trails, versioning.
    - How to Identify Your Interview Type
        - Ask Your Recruiter
            - This is the easiest and most reliable approach: just ask. Most recruiters can tell you the exact format.
            - Good questions to ask:
                - "What type of LLD round should I expect?"
                - "Will this be whiteboard-style discussion, or will I code in an IDE?"
                - "How long is the LLD round?"
                - "Should I expect concurrency topics like race conditions or deadlocks?"
                - "Will there be any database or schema design in this round?"
        - Company Research
            - If you can't get a clear answer, use company signals to make an educated guess.
            - Big Tech (US): More likely OOD (whiteboard design + discussion)
            - Indian consumer tech / startups: More likely Machine Coding
            - Fintech / trading: More likely Concurrency + performance
            - B2B SaaS: More likely API Design
            - Database / analytics companies: More likely Schema Design

