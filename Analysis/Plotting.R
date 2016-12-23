require(ggplot2)

data <- read.csv(file = "Report.txt", header = TRUE)

ggplot(data, aes(x = length.of.text)) + 
    geom_line(aes(y = Boyer.Moore, colour = "Boyer-Moore"), alpha=0.5) +
    geom_line(aes(y = Naive, colour = "Naive"), alpha = 0.5) +
    scale_colour_manual(values = c("blue", "red")) +
    ylab("Time taken, microseconds") +
    xlab("Length of text, n") + 
    ggtitle("Naive Method vs Boyer-Moore's Method")

dev.copy(png, filename = "Graph.png")
dev.off()