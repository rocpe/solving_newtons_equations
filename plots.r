###PLOTS FOR MASS1
mass1_file <- read.csv2("mass1_file.csv", comment.char = "#")
time1 <- seq.int(1, dim(mass1_file)[1])

pdf("mass1_file_all.pdf")
par(mfrow = c(3, 2))

plot(x = time1[1:3001], y = mass1_file$x[1:3001],
     grid(lwd = 2),
     ylab = expression(italic(x) ~ (m)),
     xlab = expression(italic(t) ~ (s)),
     pch = 16,
     cex = 0.7,
     col  =  "darkgreen")

plot(x = time1[1:3001], y = mass1_file$v[1:3001],
     grid(lwd = 2),
     ylab = expression(italic(v) ~ (m / s)),
     xlab = expression(italic(t) ~ (s)),
     pch = 16,
     cex = 0.7,
     col = "blue")

plot(x = time1[1:3001], y = mass1_file$Ek[1:3001],
     grid(lwd = 2),
     ylab = expression(italic(Ek) ~ (J)),
     xlab = expression(italic(t) ~ (s)),
     pch = 16,
     cex = 0.7,
     col = "red")

plot(x = time1[1:3001], y = mass1_file$Ep[1:3001],
     grid(lwd = 2),
     ylab = expression(italic(Ep) ~ (J)),
     xlab = expression(italic(t) ~ (s)),
     pch = 16,
     cex = 0.7,
     col = "magenta")

plot(x = time1[1:3001], y = mass1_file$Esum[1:3001],
     grid(lwd = 2),
     ylab = expression(italic(E[całkowita]) ~ (J)),
     xlab = expression(italic(t) ~ (s)),
     pch = 16,
     cex = 0.7,
     col = "orange")

plot(x = mass1_file$x[1:3001], y = mass1_file$v[1:3001],
     grid(lwd = 2),
     ylab = expression(italic(v) ~ (m / s)),
     xlab = expression(italic(x) ~ (m)),
     pch = 16,
     cex = 0.7,
     col = "darkblue")

dev.off()

###PLOTS FOR MASS2
mass2_file <- read.csv2("mass2_file.csv", comment.char = "#")
time2 <- seq.int(1, dim(mass2_file)[1])

pdf("mass2_file_all.pdf")
par(mfrow = c(3, 2))

plot(x = time2[1:3001], y = mass2_file$x[1:3001],
     grid(lwd = 2),
     ylab = expression(italic(x) ~ (m)),
     xlab = expression(italic(t) ~ (s)),
     pch = 16,
     cex = 0.7,
     col  =  "darkgreen")

plot(x = time2[1:3001], y = mass2_file$v[1:3001],
     grid(lwd = 2),
     ylab = expression(italic(v) ~ (m / s)),
     xlab = expression(italic(t) ~ (s)),
     pch = 16,
     cex = 0.7,
     col = "blue")

plot(x = time2[1:3001], y = mass2_file$Ek[1:3001],
     grid(lwd = 2),
     ylab = expression(italic(Ek) ~ (J)),
     xlab = expression(italic(t) ~ (s)),
     pch = 16,
     cex = 0.7,
     col = "red")

plot(x = time2[1:3001], y = mass2_file$Ep[1:3001],
     grid(lwd = 2),
     ylab = expression(italic(Ep) ~ (J)),
     xlab = expression(italic(t) ~ (s)),
     pch = 16,
     cex = 0.7,
     col = "magenta")

plot(x = time2[1:3001], y = mass2_file$Esum[1:3001],
     grid(lwd = 2),
     ylab = expression(italic(E[całkowita]) ~ (J)),
     xlab = expression(italic(t) ~ (s)),
     pch = 16,
     cex = 0.7,
     col = "orange")

plot(x = mass2_file$x[1:3001], y = mass2_file$v[1:3001],
     grid(lwd = 2),
     ylab = expression(italic(v) ~ (m / s)),
     xlab = expression(italic(x) ~ (m)),
     pch = 16,
     cex = 0.7,
     col = "darkblue")

dev.off()

###PLOTS FOR MASS3
mass3_file <- read.csv2("mass3_file.csv", comment.char = "#")
time3 <- seq.int(1, dim(mass3_file)[1])

pdf("mass3_file_all.pdf")
par(mfrow = c(3, 2))

plot(x = time3[1:3001], y = mass3_file$x[1:3001],
     grid(lwd = 2),
     ylab = expression(italic(x) ~ (m)),
     xlab = expression(italic(t) ~ (s)),
     pch = 16,
     cex = 0.7,
     col  =  "darkgreen")

plot(x = time3[1:3001], y = mass3_file$v[1:3001],
     grid(lwd = 2),
     ylab = expression(italic(v) ~ (m / s)),
     xlab = expression(italic(t) ~ (s)),
     pch = 16,
     cex = 0.7,
     col = "blue")

plot(x = time3[1:3001], y = mass3_file$Ek[1:3001],
     grid(lwd = 2),
     ylab = expression(italic(Ek) ~ (J)),
     xlab = expression(italic(t) ~ (s)),
     pch = 16,
     cex = 0.7,
     col = "red")

plot(x = time3[1:3001], y = mass3_file$Ep[1:3001],
     grid(lwd = 2),
     ylab = expression(italic(Ep) ~ (J)),
     xlab = expression(italic(t) ~ (s)),
     pch = 16,
     cex = 0.7,
     col = "magenta")

plot(x = time3[1:3001], y = mass3_file$Esum[1:3001],
     grid(lwd = 2),
     ylab = expression(italic(E[całkowita]) ~ (J)),
     xlab = expression(italic(t) ~ (s)),
     pch = 16,
     cex = 0.7,
     col = "orange")

plot(x = mass3_file$x[1:3001], y = mass3_file$v[1:3001],
     grid(lwd = 2),
     ylab = expression(italic(v) ~ (m / s)),
     xlab = expression(italic(x) ~ (m)),
     pch = 16,
     cex = 0.7,
     col = "darkblue")

dev.off()
